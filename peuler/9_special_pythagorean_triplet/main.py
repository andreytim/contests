print next((n*n - m*m) * (2*n*m) * (n*n + m*m) for m in range(999, 0, -1) for n in range(999, 0, -1) if n > m if m > 0 if (n*(n + m) == 500))
