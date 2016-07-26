(function () {
	var n = parseInt(readline());
	var a = readline().split(' ').map(function (ele) {
		return parseInt(ele);
	});
	a.push(n);
	var dp = [];
	var tr = (function (n, a) {
		var arr = [];
		for(var i = 0 ;i<n;++i) {
			arr.push(-1);
		}
		function add (p, v) {
			while(p<n) {
				var tmp = arr[p]==-1? 0 : a[arr[p]];
				//print(p);
				arr[p] = a[v]>tmp?v:arr[p];
				p+=p&(-p);
			}
		}
		function find (p) {
			var ret = p-1;
			while(p>0) {
				var tmp = arr[p]==-1? 0 : a[arr[p]];
				ret = a[ret]>tmp?ret:arr[p];
				p-=p&(-p);
			}
			return ret;
		}
		return {
			add: add,
			find: find
		}
	})(n+1, a);
	dp[n-1] = 0;
	tr.add(n,n-1);
	//print(dp[n]);
	for(var i=n-2;i>=0;--i) {
		var p = tr.find(a[i]);
		dp[i] = dp[p] + n - i - 1 - (a[i] - p - 1);
		//print(p);
		//print(dp[i]);
		tr.add(i+1,i);
	}
	for(i=1;i<n;++i)
		dp[i]+=dp[i-1];
	print(dp[n-1]);
})();