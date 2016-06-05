(function () {
	var line = readline().split(' ');
	var n = parseInt(line[0]),
	a = parseInt(line[1]);
	b = parseInt(line[2]),
	c = parseInt(line[3]),
	d = parseInt(line[4]);
	function check(v) {
		return (v<=n&&v>0);
	}
	var sum0 = a+b,
	sum1 = a+c,
	sum2 = b+d,
	sum3 = d+c;
	var ans = 0;
	for(var i=1;i<=n;++i) {
		if(check(sum0-sum1+i)&&check(sum0-sum2+i)&&check(sum0-sum3+i)) {
			ans+=n;
		}
	}
	print(ans);
})();