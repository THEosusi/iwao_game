#include "DxLib.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int maeX, maeY, maeGraph;
	int hidariGraph, migiGraph;
	int ShotX[30], ShotY[30], Shot[30], Shotflag[30], R0, R3, R4, RS, B0, B3, B4, BS, G0, G3, G4, GS, Y0, Y3, Y4, YS;
	int i,time=0;
	int now=20;
	int score=0;
	int color = GetColor(255, 255, 255);
	int miss = 0;
	int best = 0;
	int page = 0;
	int space = 0;


	for (i = 0; i < 30; i++)
	{
		Shotflag[i] = 0;
	}


	SetGraphMode(640, 480, 16);

	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	maeGraph = LoadGraph(".//a//mae.png");
	migiGraph = LoadGraph(".//a//migi.png");
	hidariGraph = LoadGraph(".//a//hidari.png");
	maeX = 288; maeY = 400;
	R0 = LoadGraph(".//a//R0.jpg");
	R3 = LoadGraph(".//a//R3.jpg");
	R4 = LoadGraph(".//a//R4.jpg");
	RS = LoadGraph(".//a//RS.jpg");
	B0 = LoadGraph(".//a//B0.jpg");
	B3 = LoadGraph(".//a//B3.jpg");
	B4 = LoadGraph(".//a//B4.jpg");
	BS = LoadGraph(".//a//BS.jpg");
	G0 = LoadGraph(".//a//G0.jpg");
	G3 = LoadGraph(".//a//G3.jpg");
	G4 = LoadGraph(".//a//G4.jpg");
	GS = LoadGraph(".//a//GS.jpg");
	Y0 = LoadGraph(".//a//Y0.jpg");
	Y3 = LoadGraph(".//a//Y3.jpg");
	Y4 = LoadGraph(".//a//Y4.jpg");
	YS = LoadGraph(".//a//YS.jpg");
	

	//移動
	while (1)
	{
		if (page == 0) {
			ClearDrawScreen();
			SetFontSize(50);
			DrawFormatString(0, 200, color, "　　　　岩男");
			SetFontSize(30);
			DrawFormatString(200, 350, color, "PUSH:SPACE KEY");
			if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
				page++;
				space++;
			}
			ScreenFlip();
	       }
		else if (page ==1) {
			ClearDrawScreen();
			SetFontSize(30);
			DrawFormatString(0, 0, color, "取った図形に関係ある図形を取り、点数を");
			DrawFormatString(0, 30, color, "伸ばそう(色や形をつなげる）");
			DrawFormatString(0, 60, color, "矢印キーで移動");
			LoadGraphScreen(0, 100, ".//a//rule.png", FALSE);
			SetFontSize(25);
			DrawFormatString(400, 400, color, "PUSH SPACE KEY");
			if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
				WaitTimer(1300);
				if (space >= 1) {
					space = 0;
				}
				else {
					page++;
				}
			}
			ScreenFlip();
			
		}
		else if (page >= 2) {
		

			ClearDrawScreen();
			{    // ↑キーを押していたらを上に移動させる
				if (CheckHitKey(KEY_INPUT_UP) == 1) {
					maeY -= 5;
					if (maeX < 0)maeX = 0;
					if (maeX > 640 - 35)maeX = 640 - 35;
					if (maeY < 0)maeY = 0;
					if (maeY > 480 - 40)maeY = 480 - 40;
					DrawGraph(maeX, maeY, maeGraph, FALSE);
				}


				// ↓キーを押していたらを下に移動させる
				else if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
					maeY += 5;
					if (maeX < 0)maeX = 0;
					if (maeX > 640 - 35)maeX = 640 - 35;
					if (maeY < 0)maeY = 0;
					if (maeY > 480 - 40)maeY = 480 - 40;
					DrawGraph(maeX, maeY, maeGraph, FALSE);
				}

				// ←キーを押していたらを左に移動させる
				else if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
					maeX -= 5;
					if (maeX < 0)maeX = 0;
					if (maeX > 640 - 35)maeX = 640 - 35;
					if (maeY < 0)maeY = 0;
					if (maeY > 480 - 40)maeY = 480 - 40;
					DrawGraph(maeX, maeY, hidariGraph, FALSE);
				}

				// →キーを押していたらを右に移動させる
				else if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
					maeX += 5;
					if (maeX < 0)maeX = 0;
					if (maeX > 640 - 35)maeX = 640 - 35;
					if (maeY < 0)maeY = 0;
					if (maeY > 480 - 40)maeY = 480 - 40;
					DrawGraph(maeX, maeY, migiGraph, FALSE);
				}
				//何もしてないときは前
				else { DrawGraph(maeX, maeY, maeGraph, FALSE); }

			}

			//球の操作

			time++;
			if (miss == 0) {
				for (i = 0;i < 30;i++) {
					if (time == 10) {
						if (Shotflag[i] == 0) {
							ShotX[i] = GetRand(617);
							ShotY[i] = 0;

							Shotflag[i] = 1;
							Shot[i] = GetRand(15);

							time = 0;
						}

					}
				}
			}

			for (i = 0;i < 30;i++) {
				if (Shotflag[i] == 1)
				{
					if (Shot[i] == 0) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], R0, FALSE);
					}
					else if (Shot[i] == 1) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], R3, FALSE);
					}
					else if (Shot[i] == 2) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], R4, FALSE);
					}
					else if (Shot[i] == 3) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], RS, FALSE);
					}
					else if (Shot[i] == 4) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], B0, FALSE);
					}
					else if (Shot[i] == 5) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], B3, FALSE);
					}
					else if (Shot[i] == 6) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], B4, FALSE);
					}
					else if (Shot[i] == 7) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], BS, FALSE);
					}
					else if (Shot[i] == 8) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], G0, FALSE);
					}
					else if (Shot[i] == 9) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], G3, FALSE);
					}
					else if (Shot[i] == 10) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], G4, FALSE);
					}
					else if (Shot[i] == 11) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], GS, FALSE);
					}
					else if (Shot[i] == 12) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], Y0, FALSE);
					}
					else if (Shot[i] == 13) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], Y3, FALSE);
					}
					else if (Shot[i] == 14) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], Y4, FALSE);
					}
					else if (Shot[i] == 15) {
						ShotY[i] += 7;
						if (ShotY[i] > 513) {
							Shotflag[i] = 0;
						}
						DrawGraph(ShotX[i], ShotY[i], YS, FALSE);
					}
				}
			}
			for (i = 0;i < 30;i++) {
				if (Shotflag[i] == 1)
				{
					if (((ShotX[i] > maeX && ShotX[i] < maeX + 35) || (maeX > ShotX[i] && maeX < ShotX[i] + 23)) && ((ShotY[i] > maeY && ShotY[i] < maeY + 40) || (maeY > ShotY[i] && maeY < ShotY[i] + 23)))
					{
						if (now == 0) {
							if (Shot[i] == 0 || Shot[i] == 1 || Shot[i] == 2 || Shot[i] == 3 || Shot[i] == 4 || Shot[i] == 8 || Shot[i] == 12) {

								now = Shot[i];
								Shotflag[i] = 0;
								
								score++;
							}

							else {

								miss++;
							}
						}
						else if (now == 1) {
							if (Shot[i] == 0 || Shot[i] == 1 || Shot[i] == 2 || Shot[i] == 3 || Shot[i] == 5 || Shot[i] == 9 || Shot[i] == 13) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								miss++;
							}
						}
						else if (now == 2) {
							if (Shot[i] == 0 || Shot[i] == 1 || Shot[i] == 2 || Shot[i] == 3 || Shot[i] == 6 || Shot[i] == 10 || Shot[i] == 14) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								miss++;
							}
						}
						else if (now == 3) {
							if (Shot[i] == 0 || Shot[i] == 1 || Shot[i] == 2 || Shot[i] == 3 || Shot[i] == 7 || Shot[i] == 11 || Shot[i] == 15) {

								now = Shot[i];
								Shotflag[i] = 0;

							
								score++;
							}
							else {
								miss++;
							}
						}
						else if (now == 4) {
							if (Shot[i] == 4 || Shot[i] == 5 || Shot[i] == 6 || Shot[i] == 7 || Shot[i] == 0 || Shot[i] == 8 || Shot[i] == 12) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								miss++;
							}
						}
						else if (now == 5) {
							if (Shot[i] == 4 || Shot[i] == 5 || Shot[i] == 6 || Shot[i] == 7 || Shot[i] == 1 || Shot[i] == 9 || Shot[i] == 13) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								miss++;
							}
						}
						else if (now == 6) {
							if (Shot[i] == 4 || Shot[i] == 5 || Shot[i] == 6 || Shot[i] == 7 || Shot[i] == 2 || Shot[i] == 10 || Shot[i] == 14) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								miss++;
							}
						}
						else if (now == 7) {
							if (Shot[i] == 4 || Shot[i] == 5 || Shot[i] == 6 || Shot[i] == 7 || Shot[i] == 3 || Shot[i] == 11 || Shot[i] == 15) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}
						}
						else if (now == 8) {
							if (Shot[i] == 8 || Shot[i] == 9 || Shot[i] == 10 || Shot[i] == 11 || Shot[i] == 0 || Shot[i] == 4 || Shot[i] == 12) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}

						}
						else if (now == 9) {
							if (Shot[i] == 8 || Shot[i] == 9 || Shot[i] == 10 || Shot[i] == 11 || Shot[i] == 1 || Shot[i] == 5 || Shot[i] == 13) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}

						}
						else if (now == 10) {
							if (Shot[i] == 8 || Shot[i] == 9 || Shot[i] == 10 || Shot[i] == 11 || Shot[i] == 2 || Shot[i] == 6 || Shot[i] == 14) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}

						}
						else if (now == 11) {
							if (Shot[i] == 8 || Shot[i] == 9 || Shot[i] == 10 || Shot[i] == 11 || Shot[i] == 3 || Shot[i] == 7 || Shot[i] == 15) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}

						}
						else if (now == 12) {
							if (Shot[i] == 12 || Shot[i] == 13 || Shot[i] == 14 || Shot[i] == 15 || Shot[i] == 0 || Shot[i] == 4 || Shot[i] == 8) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}
						}
						else if (now == 13) {
							if (Shot[i] == 12 || Shot[i] == 13 || Shot[i] == 14 || Shot[i] == 15 || Shot[i] == 1 || Shot[i] == 5 || Shot[i] == 9) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}

						}
						else if (now == 14) {
							if (Shot[i] == 12 || Shot[i] == 13 || Shot[i] == 14 || Shot[i] == 15 || Shot[i] == 2 || Shot[i] == 6 || Shot[i] == 10) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								//gameoverを書く
								miss++;
							}
						}
						else if (now == 15) {
							if (Shot[i] == 12 || Shot[i] == 13 || Shot[i] == 14 || Shot[i] == 15 || Shot[i] == 3 || Shot[i] == 7 || Shot[i] == 11) {

								now = Shot[i];
								Shotflag[i] = 0;

								
								score++;
							}
							else {
								miss++;

							}
						}
						else if (now == 20) {

							now = Shot[i];
							Shotflag[i] = 0;

							
							score++;
						}
					}
				}
			}
			if (miss == 0) {
				SetFontSize(15);
				DrawFormatString(0, 0, color, "得点%d", score);
				DrawFormatString(0, 32, color, "最高得点%d", best);
			}
			if (miss >= 1) {

				SetFontSize(50);
				DrawFormatString(150, 150, color, "ゲームオーバー");
				DrawFormatString(150, 200, color, "    得点%d", score);
				SetFontSize(40);
				DrawFormatString(150, 255, color, "　R:リスタート");
				if (best < score) {
					best = score;
				}

			}
			ScreenFlip();
			if (CheckHitKey(KEY_INPUT_R)) {
				score = 0;
				miss = 0;
				now = 20;
				for (i = 0; i < 30; i++)
				{
					Shotflag[i] = 0;
				}
				time = 0;

			}
		}
		if (ProcessMessage() < 0)break;

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	}
	DxLib_End();
	return 0;
}