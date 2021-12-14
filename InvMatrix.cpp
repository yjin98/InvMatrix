#include <iostream>
#include <vector>

std::vector<std::vector<double>> InvrMat(std::vector<std::vector<double>> m)
{
	std::vector<double> cmr, cnr;
	int s = m.size(), i, j, k;
	double p, q;
	std::vector<double> nr(s);
	std::vector<std::vector<double>> n(s, nr);
	for (i = 0; i < s; i++) {
		n[i][i] = 1;
	}

	for (i = 0; i < s; i++) {
		while (m[i][i] == 0) {
			j = i + 1;
			while (m[j][i] == 0) {
				j = j + 1;
			}
			cmr = m[j];
			cnr = n[j];
			m[j] = m[i];
			n[j] = n[i];
			m[i] = cmr;
			n[i] = cnr;
		}
		
		p = m[i][i];
		for (j = i; j < s; j++) {
			m[i][j] = m[i][j] / p;
			n[i][j] = n[i][j] / p;
		}

		for (k = 0; k < i; k++) {
			q = m[k][i];
			for (j = i; j < s; j++) {
				m[k][j] = m[k][j] - q * m[i][j];
				n[k][j] = n[k][j] - q * n[i][j];
			}
		}

		for (k = i + 1; k < s; k++) {
			q = m[k][i];
			for (j = i; j < s; j++) {
				m[k][j] = m[k][j] - q * m[i][j];
				n[k][j] = n[k][j] - q * n[i][j];
			}
		}
	}

	return n;
}
