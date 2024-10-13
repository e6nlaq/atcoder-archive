// C++の機能を全部使えるようにする魔法の言葉
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;     // 整数Nの変数を宣言
    string S;  // 文字列Sの変数を宣言

    // NとSを受け取る
    cin >> N >> S;

    // 0~N-1文字までを処理する
    // これは変数iを宣言して、iがN-1になるまで、中の処理を実行して1増やすことをしている。
    // 中の処理は、i文字目にどんなことをするかを記述する
    for (int i = 0; i < N; ++i) {
        // i文字目がJならOに変更
        if (S[i] == 'J') {
            S[i] = 'O';
        }
        // Jではなく、OならIに変更
        else if (S[i] == 'O') {
            S[i] = 'I';
        }
        // JでもOでもなく、IならJに変更
        else if (S[i] == 'I') {
            S[i] = 'J';
        }
    }

    // 変更後の文字列(答え)を出力する
    cout << S << endl;

    // 正常に終了させる
    return 0;
}
