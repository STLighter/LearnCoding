//(function () {
	// function Queue (amount) {
	// 	if(!(this instanceof Queue)) {
	// 		return new Queue(amount);
	// 	}
	// 	amount = amount||64;
	// 	this.amount = amount;
	// 	this.bg = 0;
	// 	this.ed = 0;
	// 	this.arr = [];
	// }
	// Queue.prototype = {
	// 	constractor: Queue,
	// 	isEmpty: function () {
	// 		return (this.bg === this.ed);
	// 	},
	// 	doubleSize: function () {
	// 		var target = [],
	// 			o = this.arr,
	// 			i = this.bg,
	// 			j = this.ed,
	// 			l = this.amount;
	// 		target.push(o[i])
	// 		i=(i+1)%l;
	// 		for(;i!=j;i=(i+1)%l)
	// 			target.push(o[i]);
	// 		this.amount *= 2;
	// 		this.bg = 0;
	// 		this.ed = target.length;
	// 		this.arr = target;
	// 		//print(this.arr);
	// 	},
	// 	push: function (o) {
	// 		this.arr[this.ed] = o;
	// 		this.ed = (this.ed+1)%this.amount;
	// 		// if(this.isEmpty()) {
	// 		// 	this.doubleSize();
	// 		// }
	// 	},
	// 	pop: function () {
	// 		var idx = this.bg;
	// 		this.bg = (this.bg+1)%this.amount;
	// 		return this.arr[idx];
	// 	}
	// }
	var rotater = (function () {
		var _door = [
			['*'],
			['^','>','v','<'],
			['-','|'], 
			['L','U','R','D'],
			['+']
		];
		var _todoor = {},
			i,
			j,
			l;
		for(i=0;i<5;++i) {
			l = _door[i].length;
			for(j=0;j<l;++j) {
				_todoor[_door[i][j]] = {
					x: i,
					y: j,
					l: l
				};
			}
		}
		function rotateOne (c) {
			var di = _todoor[c];
			return _door[di.x][(di.y+1)%di.l];
		}
		function rotate (v) {
			var ret = [],
				tmp;
			for(var i=0,li=v.length;i<li;++i){
				tmp = "";
				for(var j=0,lj=v[i].length;j<lj;++j) {
					tmp+=rotateOne(v[i][j]);
				}
				ret.push(tmp);
			}
			return ret;
		}
		return {
			rotate: rotate
		}
	})();
	var steps = [
		[0,1],
		[1,0],
		[0,-1],
		[-1,0]
	];
	var rules = (function () {
		var right = ['+','-','>','L','U','D'];
		var down = ['+','|','v','L','R','U'];
		var left = ['+','-','<','D','R','U'];
		var up = ['+','|','^','D','R','L'];
		function lg (c, d) {
			for(var i=d.length-1;i>=0;--i) {
				if(d[i]===c)
					return true;
			}
			return false;
		}
		return [
			function (a,b) {
				return lg(a,right)&&lg(b,left);
			},
			function (a,b) {
				return lg(a,down)&&lg(b,up);
			},
			function (a,b) {
				return lg(a,left)&&lg(b,right);
			},
			function (a,b) {
				return lg(a,up)&&lg(b,down);
			}
		];
	})();
	function readlineInt () {
		return readline().split(' ').map(function (e) {
			return parseInt(e);
		});
	}
	var line = readlineInt();
	var n = line[0],
		m = line[1];
	var vec = [];
	for(var i=0;i<n;++i)
		vec.push(readline());
	var st = readlineInt();
	var ed = readlineInt();
	st = st.map(function (e) {
		return e-1;
	});
	ed = ed.map(function (e) {
		return e-1;
	});
	var allv = [];
	allv.push(vec);
	var i,vtmp;
	for(i=0;i<3;++i) {
		vtmp = rotater.rotate(vec);
		allv.push(vtmp);
		vec = vtmp;
	}
	// allv.forEach(function (e) {
	// 	print(e);
	// })
	st.push(0);
	//var qu = [];
	//var qu = new Queue(1000*1000*4+10);
	var qu = [];
	var lidx = 0,ridx=1;
	var amount = 1000*1000*4+10;
	var used = [];
	qu[0] = {
		p: st,
		l: 0
	};
	used[(st[0]*m+st[1])*4+st[2]] = true;

	
	var cur;
	var nxt;
	var ans = -1;
	var j,k,x,xx,ii,jj;
	//var idx = 0;
	while(/*qu.length > idx*//*!qu.isEmpty()*/lidx!=ridx) {
		//cur = qu[idx];
		//cur = qu.pop();
		cur = qu[lidx];
		lidx = (lidx+1)%amount;
		//++idx;
		  // print("i:"+cur.p[0]);
		  // print("j:"+cur.p[1]);
		  // print("x:"+cur.p[2]);
		  // print("l:"+cur.l);
		if(cur.p[0] === ed[0] && cur.p[1] === ed[1]) {
			qu = [];
			ans = cur.l;
			break;
		}
		i = cur.p[0];
		j = cur.p[1];
		x = cur.p[2];
		for(k=0;k<4;++k){
			ii = i + steps[k][0];
			jj = j + steps[k][1];
			if(ii>=0&&ii<n&&jj>=0&&jj<m&&!used[(ii*m+jj)*4+x]) {
				if(rules[k](allv[x][i][j],allv[x][ii][jj])) {
					// qu.push({
					// 	p: [ii,jj,x],
					// 	l: cur.l+1
					// });
					qu[ridx] = {
						p: [ii,jj,x],
						l: cur.l+1
					};
					ridx = (ridx+1)%amount;
					used[(ii*m+jj)*4+x] = true;
				}
			}
		}
		xx = (x+1)%4;
		if(!used[(i*m+j)*4+xx]) {
			// qu.push({
			// 	p: [i,j,xx],
			// 	l: cur.l+1
			// });
			qu[ridx] = {
				p: [i,j,xx],
				l: cur.l+1
			}
			ridx = (ridx+1)%amount;
			used[(i*m+j)*4+xx] = true;
		}
	}
	print(ans);
//})();