(function () {
	var n = parseInt(readline());
	var arr = readline().split(' ').map(function (ele){
		return parseInt(ele);
	});
	var disArr = [];
	arr.forEach(function (ele, idx) {
		disArr.push({
			idx: idx,
			v: ele
		});
	});
	disArr.sort(function (a,b) {
		return a.v - b.v;
	});
	disArr.forEach(function (ele, idx) {
		arr[ele.idx] = idx + 1;
	});
	var ans = [];
	for(var i=0;i<n;++i) {
		ans.push({
			left: -1,
			right: -1,
			father: -1
		});
	}
	var tr = (function (n) {
		var arr = [];
		for(var i=0;i<n;++i) {
			arr.push(0);
		}
		function add (p) {
			//print(p);
			for(;p<n;p+=p&(-p))
				++arr[p];
		}
		function find (p) {
			var ret = 0;
			//print(p);
			for(;p>0;p-=p&(-p))
				ret+=arr[p];
			return ret;
		}
		function lfind (v,l,r) {
			var mid;
			while(l<r) {
				mid = Math.floor((l+r)/2);
				if(find(mid)<v) {
					l=mid+1;
				} else {
					r=mid;
				}
				//print('l'+l);
				//print('r'+r);
			}
			return l;
		}
		function rfind (v,l,r) {
			var mid;
			while(l<r) {
				mid = Math.floor((l+r)/2);
				if(find(mid)>v) {
					r=mid;
				} else {
					l=mid+1;
				}
			}
			return l;
		}
		return {
			'add': add,
			'find': find,
			'lfind': lfind,
			'rfind': rfind
		}
	})(n+1);

	arr.forEach(function (ele, idx) {
		//print(ele);
		if(idx === 0) {
			tr.add(ele);
			return;
		}
		var x = tr.lfind(tr.find(ele),0,ele),
			y = tr.rfind(tr.find(ele),ele,n);
		if(x!=0)
			x = disArr[x-1].idx;
		else
			x = -1;
		y = disArr[y-1].idx;
		if(x!=-1&&ans[x].right === -1) {
			ans[x].right = idx;
			ans[idx].father = x;
		} else {
			ans[y].left = idx;
			ans[idx].father = y;
		}
		tr.add(ele);
	});
	// ans.forEach(function (ele) {
	// 	print(JSON.stringify(ele));
	// });
	var pt = [];
	for(i=1;i<n;++i) {
		pt.push(disArr[arr[ans[i].father]-1].v);
	}
	print(pt.join(' '));
})();