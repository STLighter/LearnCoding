(function () {
	var line = readline().split(' ').map(function (e) {
		return parseInt(e);
	});
	var n = line[0],
		k = line[1];
	var s = readline();
	
	var ans1 = getAns(s,k,'a'),
		ans2 = getAns(s,k,'b');
	ans1 = ans1>ans2?ans1:ans2;
	print(ans1);

	function getAns (str, k, c) {
		var p = -1,
			nxt = 0,
			seg = [],
			l = str.length;
		do {
			nxt = str.indexOf(c, p+1);
			if(nxt<0)
				nxt = l;
			seg.push(nxt - p - 1);
			p = nxt;
		} while(p<l);
		if(seg.length<=k+1)
			return l;
		var i,
			j,
			ret,
			tmp=0;
		l = seg.length;
		for(i=0;i<=k;++i) {
			tmp += seg[i];
		}
		ret = tmp;
		for(j=0;i<l;++i,++j) {
			tmp+=seg[i]-seg[j];
			ret = tmp>ret?tmp:ret;
		}
		return ret+k;
	}
	
})();