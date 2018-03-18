#include <cstdio>
using namespace std;
using LL = long long;

struct Nd;
struct Rt;
Rt *_rtget();
Nd *_ndget();

struct Nd {
	LL key, count;
	Rt *left, *right;
};

struct Rt {
	Nd *root;
	int height;

	void insert(LL key) {
		if(root == nullptr) {
			root = _ndget();
			*root = Nd{key, 1, _rtget(), _rtget()};
			height = 1;
			return;
		}

		if(key > root->key) { ++root->count; root->right->insert(key); }
		else if(key < root->key) { root->left->insert(key); }
		else { ++root->count; return; }

		rebal(getBal());
	}

	LL find(LL key) {
		LL ret;
		if(root == nullptr) ret = 0;
		else if(key > root->key) ret = root->right->find(key);
		else {
			ret = root->count;
			if(key < root->key) ret += root->left->find(key);
		}
		return ret;
	}

	int getBal() {
		int lh = root->left->height, rh = root->right->height;
		height = 1+(lh>rh?lh:rh);
		return rh-lh;
	}

	void rebal(int bal) {
		if(bal < -1) {
			if(root->left->getBal() > 0) root->left->lrot();
			rrot();
		}
		else if(bal > 1) {
			if(root->right->getBal() < 0) root->right->rrot();
			lrot();
		}
	}

	void lrot() {
		auto A = root->right->root;
		auto B = A->left;
		*root->right = *B;
		root->count = root->count - A->count;
		B->root = root;
		root = A;
		root->left->getBal();
		getBal();
	}

	void rrot() {
		auto A = root->left->root;
		auto B = A->right;
		*root->left = *B;
		A->count = A->count + root->count;
		B->root = root;
		root = A;
		root->right->getBal();
		getBal();
	}
};

int _Irt, _Ind;
Rt *_rta;
Nd *_nda;
Rt *_rtget() { _rta[_Irt] = Rt{nullptr, 0}; return &_rta[_Irt++]; }
Nd *_ndget() { return &_nda[_Ind++]; }

LL solve() {
	int N, P;
	_Irt = _Ind = 0;
	scanf("%d %d", &N, &P);
	LL offset = 0, answ = 0;
	Rt tree{nullptr, 0};
	for(int i=0; i<N; ++i) {
		int s;
		scanf("%d", &s);
		s -= P;
		tree.insert(-offset);
		offset += s;
		answ += tree.find(-offset);
	}
	return answ;
}

int main() {
	_rta = new Rt[3000000];
	_nda = new Nd[2000000];
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		printf("#%d %lld\n", t, solve());
	}
	delete[] _rta;
	delete[] _nda;
	return 0;
}