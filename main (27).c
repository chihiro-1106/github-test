#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player, computer;

    // 手の名前表示用配列
    const char *hands[] = {"グー", "チョキ", "パー"};

    // 乱数初期化
    srand(time(NULL));

    // プレイヤーの入力
    printf("じゃんけんゲーム！\n");
    printf("あなたの手を選んでください（0:グー, 1:チョキ, 2:パー）: ");
    scanf("%d", &player);

    if(player < 0 || player > 2) {
        printf("無効な入力です。\n");
        return 1;
    }

    // コンピュータの手（0～2の乱数）
    computer = rand() % 3;

    // 結果表示
    printf("あなた: %s\n", hands[player]);
    printf("コンピュータ: %s\n", hands[computer]);

    // 勝敗判定
    if(player == computer) {
        printf("あいこです！\n");
    } else if((player == 0 && computer == 1) ||
              (player == 1 && computer == 2) ||
              (player == 2 && computer == 0)) {
        printf("あなたの勝ちです！\n");
    } else {
        printf("コンピュータの勝ちです！\n");
    }

    return 0;
}
