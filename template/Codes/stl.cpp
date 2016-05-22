/*
 *	bool next_permutation(a, a + n);
 *	true: 	has next permutation and 
 *			change a[n] into the next permutation
 *	false:	the a[n] now is the last permutation
 */

//sample code:
sort(a, a + len);
do {
	for (int i = 0; i < len; i++)
		cout << a[i];
	cout << endl;
} while(next_permutation(a, a + len));
