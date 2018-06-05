// The main function that returns maximum product obtainable
// from a rope of length n
unordered_map <int, int> dp;
int maxProd(int n)
{
	// Base cases
	if (dp.find(n) != dp.end()) return dp[n];
    int result = 1;
    for (int i = 1; i < n; i++) {
        result = max (result, max(i*(n-1), i*maxProd(n-1)));
    }
    dp[n] = result;
	return result;
}

/* Driver program to test above functions */
int main()
{
	cout << "Maximum Product is " << maxProd(10);
	return 0;
}

