window.onload = function () {
	waterfall('main', 'box');
	var dataInt = {
		"data": [
			{"src": 'images/(14).png'},
			{"src": 'images/(23).png'},
			{"src": 'images/(33).png'},
			{"src": 'images/(34).png'},
		]
	}
	window.onscroll = function () {
		if(checkScrollSlide()) {
			var oParent = document.getElementById('main');
			for(var i=0;i<dataInt.data.length;++i) {
				var oBox = document.createElement('div');
				oBox.className = 'box';
				oParent.appendChild(oBox);
				var oPic = document.createElement('div');
				oPic.className = 'pic';
				oBox.appendChild(oPic);
				var oImg = document.createElement('img');
				oImg.src = dataInt.data[i].src;
				oPic.appendChild(oImg);
			}
		}
		waterfall('main', 'box');
	}
}

function waterfall (parent, box) {
	// 获得main里所有box
	var oParent = document.getElementById(parent);
	var oBoxs = getByClass(oParent, box);

	// 计算整个页面显示的列数(页面宽/box宽)
	var oBoxsW = oBoxs[0].offsetWidth;
	//console.log(oBoxsW); // 兼容性??
	var cols = Math.floor(document.documentElement.clientWidth/oBoxsW);
	// 设置main的宽
	oParent.style.cssText = 'width:' + oBoxsW * cols + 'px;margin:0 auto';
	var hArr = []; //存放每列高度的数组
	for(var i=0;i<oBoxs.length;++i) {
		if(i<cols) {
			hArr.push(oBoxs[i].offsetHeight);
		} else {
			var minH = Math.min.apply(null, hArr);
			//console.log(minH);
			var index = getMinhIndex(hArr, minH);
			oBoxs[i].style.position = 'absolute';
			oBoxs[i].style.top = minH + 'px';
			//oBoxs[i].style.left = oBoxsW * index + 'px';
			oBoxs[i].style.left = oBoxs[index].offsetLeft + 'px';
			hArr[index] += oBoxs[i].offsetHeight;
		}
	}
	//console.log(hArr);
}

// 根据class获取元素
function getByClass (parent, classname) {
	var boxArr = [], // 获取所有class为classname的元素
		oElements = parent.getElementsByTagName('*');
	for(var i = 0; i < oElements.length; i++) {
		if(oElements[i].className == classname) {
			boxArr.push(oElements[i]);
		}
	}
	return boxArr;
}

function getMinhIndex (arr, val) {
	for(var i in arr) {
		if(arr[i] == val)
			return i;
	}
}
// 检测是否滚动加载数据块
function checkScrollSlide () {
	var oParent = document.getElementById('main');
	var oBoxs = getByClass(oParent, 'box');
	var lastBoxH = oBoxs[oBoxs.length - 1].offsetTop + Math.floor(oBoxs[oBoxs.length - 1].offsetHeight/2);
	var scrollTop = document.body.scrollTop || document.documentElement.scrollTop;
	var height = document.body.clientHeight || document.documentElement.clientHeight;
	//console.log(scrollTop);
	//console.log(height);
	//console.log(lastBoxH);
	return (lastBoxH<scrollTop+height)?true:false;
}