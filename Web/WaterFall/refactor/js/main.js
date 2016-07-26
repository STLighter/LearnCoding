var ST_on = (function () {
	// 局部私有变量, 缓存对应的方法
	var _addHandler,
		_removeHandler;

	// 用于给不同handler附加id
	var guid = 0;

	// 事件触发类, 管理和触发事件处理函数队列
	function HandlerEmiter () {
		
		// 局部变量为了给emit用
		var handlerQueue = {};

		// handlerQueue相当于之前的ST_events[type](fixedHandlers)
		this.handlerQueue = handlerQueue;

		// 队列大小
		this.size = 0;

		// 实际加在DOM对象上的事件处理函数, 因为调用emit的时候this可能是触发的DOM元素, 所以不能用this.handlerQueue;
		this.emit = function (event) {
			// 处理对象的兼容性
			_event = event? event: window.event;
			_target = _event.target || _event.srcElement;
			_preventDefault = function () {
				if(_event.preventDefault) {
					_event.preventDefault();
				} else {
					_event.returnValue = false;
				}
			}
			_stopPropagation = 	function () {
				if(_event.stopPropagation) {
					_event.stopPropagation();
				} else {
					_event.cancelBubble = true;
				}
			}
			// 包装成一个新的对象
			var ST_event = {
				event: _event,
				target: _target,
				preventDefault: _preventDefault,
				stopPropagation: _stopPropagation
			}

			// 顺序触发队列中的handler
			for(var id in handlerQueue) {
				if(handlerQueue[id])
					handlerQueue[id](ST_event);
			}
		}
	}
	HandlerEmiter.prototype = {
		constructor: HandlerEmiter,
		// 修正handler作用域
		fixHandler: function (context, handler) {
			// 返回一个修正作用域的handler
			return function (event) {
				// 对象兼容性在emit里面处理
				// 修正作用域
				return handler.call(context, event);
			}
		},
		// 向队列中加入事件处理函数
		addHandler: function (context, handler) {
			var fixedHandlers = this.handlerQueue;

			// 保证原handler有id
			if(!handler.ST_guid) {
				handler.ST_guid = ++guid;
			}

			// 是否已经存在
			if(!fixedHandlers[handler.ST_guid]) {
				// 不存在则修正作用域并添加
				fixedHandlers[handler.ST_guid] = this.fixHandler(context, handler);
				++this.size;
			}
				
			// 不需要实际向DOM事件中添加fixedHandlers[handler.ST_guid], 由emit方法统一调度
		},
		// 移除事件处理函数
		removeHandler: function (handler) {
			var fixedHandlers = this.handlerQueue;
			// 查找对应的fixedHandler
			if(!handler.ST_guid||!fixedHandlers[handler.ST_guid])
				return;
			// 从队列中移除fixedHandler
			fixedHandlers[handler.ST_guid] = null;
			--this.size;
		}
	}

	// 添加事件
	function add (ele, type, handler) {
		// 向dom节点对象中添加ST_handlerEmiters属性, 用来分类别缓存ST_handlerEmiter
		if(!ele.ST_handlerEmiters)
			ele.ST_handlerEmiters = {};

		// 获取对应类别用的handlerEmiter对象
		var handlerEmiter = ele.ST_handlerEmiters[type];
		if(!handlerEmiter) {
			// 第一次在该DOM对象上监听此事件, 需要加入handlerEmiter.emit()
			handlerEmiter = ele.ST_handlerEmiters[type] = new HandlerEmiter();

			// 检测缓存的addHandler方法
			if(!_addHandler) {
				// 能力检测
				if (ele.addEventListener) {
					//alert('add');
					_addHandler = function (ele, type, handler) {
						ele.addEventListener(type, handler, false);
					}
				} else if (ele.attachEvent) {
					//alert('attach');
					_addHandler = function (ele, type, handler) {
						ele.attachEvent("on" + type, handler);
					}
				} else {
					//alert('on');
					_addHandler = function (ele, type, handler) {
						ele["on" + type] = handler;
					}
					
				}
			}
			// 执行真正的添加事件处理程序方法, 加入处理程序handlerEmiter.emit()
			_addHandler.call(this, ele, type, handlerEmiter.emit);
		}
		// 之前已经绑定过handlerEmiter.emit(), 直接向队列中添加handler
		handlerEmiter.addHandler(ele, handler);
	}

	// 删除事件
	function remove (ele, type, handler) {
		// 查找缓存的fixedHandler
		if(!ele.ST_handlerEmiters)
			return;
		var handlerEmiter = ele.ST_handlerEmiters[type];
		if(!handlerEmiter)
			return;
		handlerEmiter.removeHandler(handler);
		// handlerEmiter中队列为空, 则清除Emiter
		if(handlerEmiter.size === 0) {
			// 检测缓存的removeHandler方法
			if(!_removeHandler) {
				// 能力检测
				if(ele.removeEventListener) {
					//alert('remove');
					_removeHandler = function (ele, type, handler) {
						ele.removeEventListener(type, handler, false);
					}
				} else if (ele.detachEvent) {
					//alert('detach');
					_removeHandler = function (ele, type, handler) {
						ele.detachEvent("on" + type, handler);
					}
				} else {
					//alert('on');
					_removeHandler = function (ele, type, handler) {
						ele["on" + type] = null;
					}
				}
			}
			// 执行真正的删除事件方法
			_removeHandler.call(this, ele, type, handlerEmiter.emit);
			// 清除放在DOM上的属性
			ele.ST_handlerEmiters[type] = null;
		}
	}

	// 暴露接口
	return {
		addHandler: add,
		removeHandler: remove
	};

})();

ST_on.addHandler(window, 'load', function () {
	function mainClick (event) {
		alert('onclick');
		alert(event.target);
		alert(this);
		event.preventDefault();
		event.stopPropagation();
		ST_on.removeHandler(document.getElementById('main'), 'click', mainClick);
	}
	function nextClick (event) {
		alert('onNextClick');
		alert(event.target);
		alert(this);
		event.preventDefault();
		event.stopPropagation();
	}
	ST_on.addHandler(document.getElementById('main'), 'click', mainClick);
	ST_on.addHandler(document.getElementById('main'), 'click', nextClick);
});