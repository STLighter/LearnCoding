(function () {
	function Queue (amount) {
		if(!(this instanceof Queue)) {
			return new Queue(amount);
		}
		amount = amount||1024;
		this.amount = amount;
		this.bg = 0;
		this.ed = 0;
		this.arr = [];
	}
	Queue.prototype = {
		constractor: Queue,
		isEmpty: function () {
			return (this.bg === this.ed);
		},
		doubleSize: function () {
			var target = [],
				o = this.arr,
				i = this.bg,
				j = this.ed,
				l = this.amount;
			target.push(o[i])
			i=(i+1)%l;
			for(;i!=j;i=(i+1)%l)
				target.push(o[i]);
			this.amount *= 2;
			this.bg = 0;
			this.ed = target.length;
			this.arr = target;
			//print(this.arr);
		},
		push: function (o) {
			this.arr[this.ed] = o;
			this.ed = (this.ed+1)%this.amount;
			if(this.isEmpty()) {
				this.doubleSize();
			}
		},
		pop: function () {
			var idx = this.bg;
			this.bg = (this.bg+1)%this.amount;
			return this.arr[idx];
		}
	}
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
		function rotateOne (c, t) {
			t = (t===undefined?1:t);
			var di = _todoor[c];
			return _door[di.x][(di.y+t)%di.l];
		}
		return {
			rotateOne: rotateOne
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
	
	st.push(0);
	var qu = new Queue();
	var L = n*m*4;
	var used = [];
	for(var i=0; i<L;++i)
		used.push(false);
	qu.push({
		p: st,
		l: 0
	});
	used[(st[0]*m+st[1])*4+st[2]] = true;

	var cur;
	var nxt;
	var ans = -1;
	var i,j,k,x,xx,ii,jj;
	while(!qu.isEmpty()) {
		cur = qu.pop();
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
				if(rules[k](rotater.rotateOne(vec[i][j],x),rotater.rotateOne(vec[ii][jj],x))) {
					qu.push({
						p: [ii,jj,x],
						l: cur.l+1
					});
					used[(ii*m+jj)*4+x] = true;
				}
			}
		}
		xx = (x+1)%4;
		if(!used[(i*m+j)*4+xx]) {
			qu.push({
				p: [i,j,xx],
				l: cur.l+1
			});
			used[(i*m+j)*4+xx] = true;
		}
	}
	print(ans);
})();