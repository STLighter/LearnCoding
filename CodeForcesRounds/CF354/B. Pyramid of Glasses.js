(function () {
	var lines = readline().split(' ').map(function (e) {
		return parseInt(e);
	});
	var n = lines[0],
		t = lines[1];
	var a = [{
		x: t,
		y: 1
	}];
	var cnt = 0,nxt;
	for(var i=0;i<n;++i) {
		nxt = [];
		for(var j=0;j<=i;++j) {
			var tmp = {
				x: a[j].x - a[j].y,
				y: a[j].y*2
			};
			if(a[j].x>=a[j].y) {
				++cnt;
			} else {
				tmp.x = 0;
			}
			if(j) {
				nxt[j].x += tmp.x;
			} else {
				nxt.push({
					x: tmp.x,
					y: tmp.y
				});
			}
			nxt.push(tmp);
		}
		a = nxt;
	}
	print(cnt);
})()