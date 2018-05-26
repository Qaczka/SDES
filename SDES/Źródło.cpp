#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	printf("Prosze wpisac kolejne cyfry kodu binarnego: \n");

	char WPIS[8];
	int i, m;
	m = 0;
	i = 0;

	for (m = 0; m<8; m++)
	{
		WPIS[m] = 48;
		//printf("%c\n",WPIS[m]);

	}
	scanf("%s", WPIS);
	//printf("%c\n",WPIS[7]);
	//printf("%c\n",WPIS[2]);

	i = strlen(WPIS);
	printf("I to: %i", i);

	printf("%c\n", WPIS);
	printf("\n");

	//--------------------------------------------------------------------------------------//

	int KOD[8];//11001100

	for (m = 0; m<8; m++)
	{
		KOD[m] = WPIS[m] - 48;
	}
	KOD[i] = 0;//zeruje nastepny po dlugosci bo liczy jako NULL z asci

			   /*
			   for(m=0;m<8;m++)
			   {
			   printf("%i\n",KOD[m]);
			   }

			   int KOD[8];

			   for(m=0;m<8;m++)
			   {
			   scanf("%i",&KOD[m]);
			   //printf("%i\n",KOD[m]);
			   printf("Jest to bit nr: %i\n",m+1);
			   }
			   */

			   //--------------------------------------------------------------------------------------//

			   // PW

	int PW[8];

	PW[0] = KOD[1];
	PW[1] = KOD[5];
	PW[2] = KOD[2];
	PW[3] = KOD[0];
	PW[4] = KOD[3];
	PW[5] = KOD[7];
	PW[6] = KOD[4];
	PW[7] = KOD[6];

	//--------------------------------------------------------------------------------------//

	//KLUCZ KR1

	int kp[10];

	kp[0] = 1;
	kp[1] = 1;
	kp[2] = 0;
	kp[3] = 0;
	kp[4] = 0;
	kp[5] = 0;
	kp[6] = 0;
	kp[7] = 0;
	kp[8] = 1;
	kp[9] = 1;

	int P10[10];

	P10[0] = kp[2];
	P10[1] = kp[4];
	P10[2] = kp[1];
	P10[3] = kp[6];
	P10[4] = kp[3];
	P10[5] = kp[9];
	P10[6] = kp[0];
	P10[7] = kp[8];
	P10[8] = kp[7];
	P10[9] = kp[5];



	//--------------------------------------------------------------------------------------//

	//DWIE POLOWY K0 i K1

	int k0[5], k1[5];

	k0[0] = P10[0];
	k0[1] = P10[1];
	k0[2] = P10[2];
	k0[3] = P10[3];
	k0[4] = P10[4];

	k1[0] = P10[5];
	k1[1] = P10[6];
	k1[2] = P10[7];
	k1[3] = P10[8];
	k1[4] = P10[9];

	//--------------------------------------------------------------------------------------//

	// SL1

	int SL1k0[5], SL1k1[5];

	for (m = 0; m<5; m++)
	{
		SL1k0[m] = k0[(m + 1) % 5];
	}

	for (m = 0; m<5; m++)
	{
		SL1k1[m] = k1[(m + 1) % 5];
	}

	//--------------------------------------------------------------------------------------//

	//P10w8 kl 1

	int k0k1[10], P10w8kl1[8];



	k0k1[0] = SL1k0[0];
	k0k1[1] = SL1k0[1];
	k0k1[2] = SL1k0[2];
	k0k1[3] = SL1k0[3];
	k0k1[4] = SL1k0[4];
	k0k1[5] = SL1k1[0];
	k0k1[6] = SL1k1[1];
	k0k1[7] = SL1k1[2];
	k0k1[8] = SL1k1[3];
	k0k1[9] = SL1k1[4];

	P10w8kl1[0] = k0k1[5];
	P10w8kl1[1] = k0k1[2];
	P10w8kl1[2] = k0k1[6];
	P10w8kl1[3] = k0k1[3];
	P10w8kl1[4] = k0k1[7];
	P10w8kl1[5] = k0k1[4];
	P10w8kl1[6] = k0k1[9];
	P10w8kl1[7] = k0k1[8];

	printf("KLUCZ 1 TO: ");
	for (m = 0; m<8; m++)
	{
		printf("%i", P10w8kl1[m]);
	}
	printf("\n");

	//--------------------------------------------------------------------------------------//

	//SL2

	int SL2k0[5], SL2k1[5];

	for (m = 0; m<5; m++)
	{
		SL2k0[m] = SL1k0[(m + 2) % 5];
	}

	for (m = 0; m<5; m++)
	{
		SL2k1[m] = SL1k1[(m + 2) % 5];
	}

	//--------------------------------------------------------------------------------------//

	int k0k1p[10], P10w8kl2[8];

	k0k1p[0] = SL2k0[0];
	k0k1p[1] = SL2k0[1];
	k0k1p[2] = SL2k0[2];
	k0k1p[3] = SL2k0[3];
	k0k1p[4] = SL2k0[4];
	k0k1p[5] = SL2k1[0];
	k0k1p[6] = SL2k1[1];
	k0k1p[7] = SL2k1[2];
	k0k1p[8] = SL2k1[3];
	k0k1p[9] = SL2k1[4];

	P10w8kl2[0] = k0k1p[5];
	P10w8kl2[1] = k0k1p[2];
	P10w8kl2[2] = k0k1p[6];
	P10w8kl2[3] = k0k1p[3];
	P10w8kl2[4] = k0k1p[7];
	P10w8kl2[5] = k0k1p[4];
	P10w8kl2[6] = k0k1p[9];
	P10w8kl2[7] = k0k1p[8];

	printf("KLUCZ 2 TO: ");
	for (m = 0; m<8; m++)
	{
		printf("%i", P10w8kl2[m]);
	}
	printf("\n");

	//--------------------------------------------------------------------------------------//

	//ROZDZIELENIE

	int t0[5], t1[5];

	t0[0] = PW[0];
	t0[1] = PW[1];
	t0[2] = PW[2];
	t0[3] = PW[3];

	t1[0] = PW[4];
	t1[1] = PW[5];
	t1[2] = PW[6];
	t1[3] = PW[7];

	//--------------------------------------------------------------------------------------//

	//P4w8

	int P4w8_1[8];

	P4w8_1[0] = t1[3];
	P4w8_1[1] = t1[0];
	P4w8_1[2] = t1[1];
	P4w8_1[3] = t1[2];
	P4w8_1[4] = t1[1];
	P4w8_1[5] = t1[2];
	P4w8_1[6] = t1[3];
	P4w8_1[7] = t1[0];

	//--------------------------------------------------------------------------------------//

	//XoR

	int Xor1[8];

	for (m = 0; m<8; m++)
	{
		Xor1[m] = (P4w8_1[m] + P10w8kl1[m]) % 2;
		//printf("Xor1 to: %i\n",Xor1[m]);
	}

	//--------------------------------------------------------------------------------------//

	//DZIELENIE PRZED SBOX

	int sb0[4], sb1[4];

	sb0[0] = Xor1[0];
	sb0[1] = Xor1[1];
	sb0[2] = Xor1[2];
	sb0[3] = Xor1[3];

	sb1[0] = Xor1[4];
	sb1[1] = Xor1[5];
	sb1[2] = Xor1[6];
	sb1[3] = Xor1[7];

	//--------------------------------------------------------------------------------------//

	//SBOX1

	int SBOX1[4][4];

	SBOX1[0][0] = 1;
	SBOX1[1][0] = 0;
	SBOX1[2][0] = 3;
	SBOX1[3][0] = 2;
	SBOX1[0][1] = 3;
	SBOX1[1][1] = 2;
	SBOX1[2][1] = 1;
	SBOX1[3][1] = 0;
	SBOX1[0][2] = 0;
	SBOX1[1][2] = 2;
	SBOX1[2][2] = 1;
	SBOX1[3][2] = 3;
	SBOX1[0][3] = 3;
	SBOX1[1][3] = 1;
	SBOX1[2][3] = 3;
	SBOX1[3][3] = 2;

	int SBOX2[4][4];

	SBOX2[0][0] = 0;
	SBOX2[1][0] = 1;
	SBOX2[2][0] = 2;
	SBOX2[3][0] = 3;
	SBOX2[0][1] = 2;
	SBOX2[1][1] = 0;
	SBOX2[2][1] = 1;
	SBOX2[3][1] = 3;
	SBOX2[0][2] = 3;
	SBOX2[1][2] = 0;
	SBOX2[2][2] = 1;
	SBOX2[3][2] = 0;
	SBOX2[0][3] = 2;
	SBOX2[1][3] = 1;
	SBOX2[2][3] = 0;
	SBOX2[3][3] = 3;


	//--------------------------------------------------------------------------------------//

	//ZABAWA SBOXAMI

	int wiersz, kolumna, XP0[2], XP1[2];

	XP0[0] = 0;
	XP0[1] = 0;

	wiersz = (sb0[0] * 2) + (sb0[3]);
	kolumna = (sb0[1] * 2) + (sb0[2]);

	XP0[1] = SBOX1[kolumna][wiersz] % 2;
	XP0[0] = (SBOX1[kolumna][wiersz] - XP0[1]) / 2;

	//printf("XP0 0 to: %i\n",XP0[0]);
	//printf("XP0 1 to: %i\n",XP0[1]);


	XP1[0] = 0;
	XP1[1] = 0;

	wiersz = (sb1[0] * 2) + (sb1[3]);
	kolumna = (sb1[1] * 2) + (sb1[2]);

	XP1[1] = SBOX2[kolumna][wiersz] % 2;
	XP1[0] = (SBOX2[kolumna][wiersz] - XP1[1]) / 2;

	//printf("XP1 0 to: %i\n",XP1[0]);
	//printf("XP1 1 to: %i\n",XP1[1]);

	//--------------------------------------------------------------------------------------//

	int C4[4], P4[4];
	C4[0] = XP0[0];
	C4[1] = XP0[1];
	C4[2] = XP1[0];
	C4[3] = XP1[1];

	P4[0] = C4[1];
	P4[1] = C4[3];
	P4[2] = C4[2];
	P4[3] = C4[0];

	printf("Z SBOXOW PIERWSZEJ RUNDY: ");
	for (m = 0; m<4; m++)
	{
		printf("%i", C4[m]);
	}
	printf("\n");

	//--------------------------------------------------------------------------------------//

	//Xor

	int XORM0[4];
	for (m = 0; m<4; m++)
	{
		XORM0[m] = (P4[m] + t0[m]) % 2;
		//printf("XORM0 to: %i\n",XORM0[m]);
	}

	//--------------------------------------------------------------------------------------//

	//LACZENIE KLUCZ RUNDY PIERWSZEJ

	int K1[8];

	K1[0] = XORM0[0];
	K1[1] = XORM0[1];
	K1[2] = XORM0[2];
	K1[3] = XORM0[3];
	K1[4] = t1[0];
	K1[5] = t1[1];
	K1[6] = t1[2];
	K1[7] = t1[3];

	printf("SZYFROGRAM RUNDY 1: ");
	for (m = 0; m<8; m++)
	{
		printf("%i", K1[m]);
	}
	printf("\n");


	//--------------------------------------------------------------------------------------//

	int Krzyz[8];

	Krzyz[0] = K1[4];
	Krzyz[1] = K1[5];
	Krzyz[2] = K1[6];
	Krzyz[3] = K1[7];
	Krzyz[4] = K1[0];
	Krzyz[5] = K1[1];
	Krzyz[6] = K1[2];
	Krzyz[7] = K1[3];

	int m0[4], m1[4];

	m0[0] = Krzyz[0];
	m0[1] = Krzyz[1];
	m0[2] = Krzyz[2];
	m0[3] = Krzyz[3];
	m1[0] = Krzyz[4];
	m1[1] = Krzyz[5];
	m1[2] = Krzyz[6];
	m1[3] = Krzyz[7];

	//--------------------------------------------------------------------------------------//

	//RUNDA 2

	//P10w8 kl 2

	int P4w8kl2[8];





	P4w8kl2[0] = m1[3];
	P4w8kl2[1] = m1[0];
	P4w8kl2[2] = m1[1];
	P4w8kl2[3] = m1[2];
	P4w8kl2[4] = m1[1];
	P4w8kl2[5] = m1[2];
	P4w8kl2[6] = m1[3];
	P4w8kl2[7] = m1[0];
	/*
	for(m=0;m<8;m++)
	{
	printf("P4w8kl2 to: %i\n",P4w8kl2[m]);
	}
	*/
	//--------------------------------------------------------------------------------------//

	//XoR

	int Xor_kl2[8];

	//printf("Xor_kl2 to: ");

	for (m = 0; m<8; m++)
	{
		Xor_kl2[m] = (P4w8kl2[m] + P10w8kl2[m]) % 2;
		// printf("%i",Xor_kl2[m]);
	}
	// printf("\n");

	//--------------------------------------------------------------------------------------//

	//DZIELENIE PRZED SBOX

	int sb0_2[4], sb1_2[4];

	sb0_2[0] = Xor_kl2[0];
	sb0_2[1] = Xor_kl2[1];
	sb0_2[2] = Xor_kl2[2];
	sb0_2[3] = Xor_kl2[3];

	sb1_2[0] = Xor_kl2[4];
	sb1_2[1] = Xor_kl2[5];
	sb1_2[2] = Xor_kl2[6];
	sb1_2[3] = Xor_kl2[7];


	//--------------------------------------------------------------------------------------//



	//ZABAWA SBOXAMI

	int XP0_2[2], XP1_2[2];

	XP0_2[0] = 0;
	XP0_2[1] = 0;

	wiersz = (sb0_2[0] * 2) + (sb0_2[3]);
	kolumna = (sb0_2[1] * 2) + (sb0_2[2]);

	XP0_2[1] = SBOX1[kolumna][wiersz] % 2;
	XP0_2[0] = (SBOX1[kolumna][wiersz] - XP0_2[1]) / 2;

	// printf("XP0_2 0 to: %i\n",XP0_2[0]);
	// printf("XP0_2 1 to: %i\n",XP0_2[1]);


	XP1_2[0] = 0;
	XP1_2[1] = 0;

	wiersz = (sb1_2[0] * 2) + (sb1_2[3]);
	kolumna = (sb1_2[1] * 2) + (sb1_2[2]);

	XP1_2[1] = SBOX2[kolumna][wiersz] % 2;
	XP1_2[0] = (SBOX2[kolumna][wiersz] - XP1_2[1]) / 2;

	//printf("XP1_2 0 to: %i\n",XP1_2[0]);
	// printf("XP1_2 1 to: %i\n",XP1_2[1]);


	//--------------------------------------------------------------------------------------//

	int C4_2[4], P4_2[4];
	C4_2[0] = XP0_2[0];
	C4_2[1] = XP0_2[1];
	C4_2[2] = XP1_2[0];
	C4_2[3] = XP1_2[1];

	P4_2[0] = C4_2[1];
	P4_2[1] = C4_2[3];
	P4_2[2] = C4_2[2];
	P4_2[3] = C4_2[0];

	printf("Z SBOXOW DRUGIEJ RUNDY: ");
	for (m = 0; m<4; m++)
	{
		printf("%i", C4_2[m]);
	}
	printf("\n");


	//--------------------------------------------------------------------------------------//

	//Xor

	int XORM0_2[4];
	for (m = 0; m<4; m++)
	{
		XORM0_2[m] = (P4_2[m] + m0[m]) % 2;
		//printf("XORM0_2 to: %i\n",XORM0_2[m]);
	}

	//--------------------------------------------------------------------------------------//

	//LACZENIE KLUCZ RUNDY PIERWSZEJ

	int K2[8];

	K2[0] = XORM0_2[0];
	K2[1] = XORM0_2[1];
	K2[2] = XORM0_2[2];
	K2[3] = XORM0_2[3];
	K2[4] = m1[0];
	K2[5] = m1[1];
	K2[6] = m1[2];
	K2[7] = m1[3];

	printf("SZYFROGRAM RUNDY 2 TO: ");

	for (m = 0; m<8; m++)
	{
		printf("%i", K2[m]);
	}
	printf("\n");

	//--------------------------------------------------------------------------------------//

	int PO[8];

	PO[0] = K2[3];
	PO[1] = K2[0];
	PO[2] = K2[2];
	PO[3] = K2[4];
	PO[4] = K2[6];
	PO[5] = K2[1];
	PO[6] = K2[7];
	PO[7] = K2[5];

	printf("SZYFROGRAM KONCOWY TO: ");

	for (m = 0; m<8; m++)
	{
		printf("%i", PO[m]);
	}
	printf("\n");
	printf("\n");
	printf("\n");



	//--------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------////--------------------------------------------------------------------------------------////--------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------//



	//--------------------------------------------------------------------------------------//

	// PW

	for (m = 0; m<8; m++)
	{
		scanf("%i", &PO[m]);
	}


	PW[0] = PO[1];
	PW[1] = PO[5];
	PW[2] = PO[2];
	PW[3] = PO[0];
	PW[4] = PO[3];//0
	PW[5] = PO[7];//1
	PW[6] = PO[4];//2
	PW[7] = PO[6];//3


	printf("PW TO: ");

	for (m = 0; m<8; m++)
	{
		printf("%i", PW[m]);
	}
	printf("\n");


	//--------------------------------------------------------------------------------------//
	//RUNDA 2

	//P10w8 kl 2






	P4w8kl2[0] = PW[7];
	P4w8kl2[1] = PW[4];
	P4w8kl2[2] = PW[5];
	P4w8kl2[3] = PW[6];
	P4w8kl2[4] = PW[5];
	P4w8kl2[5] = PW[6];
	P4w8kl2[6] = PW[7];
	P4w8kl2[7] = PW[4];
	/*
	for(m=0;m<8;m++)
	{
	printf("P4w8kl2 to: %i\n",P4w8kl2[m]);
	}
	*/
	//--------------------------------------------------------------------------------------//

	//XoR


	//printf("Xor_kl2 to: ");

	for (m = 0; m<8; m++)
	{
		Xor_kl2[m] = (P4w8kl2[m] + P10w8kl2[m]) % 2;
		// printf("%i",Xor_kl2[m]);
	}
	// printf("\n");

	//--------------------------------------------------------------------------------------//

	//DZIELENIE PRZED SBOX


	sb0_2[0] = Xor_kl2[0];
	sb0_2[1] = Xor_kl2[1];
	sb0_2[2] = Xor_kl2[2];
	sb0_2[3] = Xor_kl2[3];

	sb1_2[0] = Xor_kl2[4];
	sb1_2[1] = Xor_kl2[5];
	sb1_2[2] = Xor_kl2[6];
	sb1_2[3] = Xor_kl2[7];


	//--------------------------------------------------------------------------------------//



	//ZABAWA SBOXAMI


	XP0_2[0] = 0;
	XP0_2[1] = 0;

	wiersz = (sb0_2[0] * 2) + (sb0_2[3]);
	kolumna = (sb0_2[1] * 2) + (sb0_2[2]);

	XP0_2[1] = SBOX1[kolumna][wiersz] % 2;
	XP0_2[0] = (SBOX1[kolumna][wiersz] - XP0_2[1]) / 2;

	// printf("XP0_2 0 to: %i\n",XP0_2[0]);
	// printf("XP0_2 1 to: %i\n",XP0_2[1]);


	XP1_2[0] = 0;
	XP1_2[1] = 0;

	wiersz = (sb1_2[0] * 2) + (sb1_2[3]);
	kolumna = (sb1_2[1] * 2) + (sb1_2[2]);

	XP1_2[1] = SBOX2[kolumna][wiersz] % 2;
	XP1_2[0] = (SBOX2[kolumna][wiersz] - XP1_2[1]) / 2;

	//printf("XP1_2 0 to: %i\n",XP1_2[0]);
	// printf("XP1_2 1 to: %i\n",XP1_2[1]);


	//--------------------------------------------------------------------------------------//

	C4_2[0] = XP0_2[0];
	C4_2[1] = XP0_2[1];
	C4_2[2] = XP1_2[0];
	C4_2[3] = XP1_2[1];

	P4_2[0] = C4_2[1];
	P4_2[1] = C4_2[3];
	P4_2[2] = C4_2[2];
	P4_2[3] = C4_2[0];

	printf("Z SBOXOW DRUGIEJ RUNDY: ");
	for (m = 0; m<4; m++)
	{
		printf("%i", C4_2[m]);
	}
	printf("\n");


	//--------------------------------------------------------------------------------------//

	//Xor

	for (m = 0; m<4; m++)
	{
		XORM0_2[m] = (P4_2[m] + PW[m]) % 2;
		//printf("XORM0_2 to: %i\n",XORM0_2[m]);
	}

	//--------------------------------------------------------------------------------------//

	//LACZENIE KLUCZ RUNDY PIERWSZEJ


	K2[0] = XORM0_2[0];
	K2[1] = XORM0_2[1];
	K2[2] = XORM0_2[2];
	K2[3] = XORM0_2[3];
	K2[4] = PW[4];
	K2[5] = PW[5];
	K2[6] = PW[6];
	K2[7] = PW[7];

	printf("SZYFROGRAM RUNDY 2 TO: ");

	for (m = 0; m<8; m++)
	{
		printf("%i", K2[m]);
	}
	printf("\n");

	//-------------------------------------------------------------------------


	Krzyz[0] = K2[4];
	Krzyz[1] = K2[5];
	Krzyz[2] = K2[6];
	Krzyz[3] = K2[7];
	Krzyz[4] = K2[0];
	Krzyz[5] = K2[1];
	Krzyz[6] = K2[2];
	Krzyz[7] = K2[3];


	m0[0] = Krzyz[0];
	m0[1] = Krzyz[1];
	m0[2] = Krzyz[2];
	m0[3] = Krzyz[3];
	m1[0] = Krzyz[4];
	m1[1] = Krzyz[5];
	m1[2] = Krzyz[6];
	m1[3] = Krzyz[7];

	//--------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------//

	//ROZDZIELENIE



	t0[0] = m0[0];
	t0[1] = m0[1];
	t0[2] = m0[2];
	t0[3] = m0[3];

	t1[0] = m1[0];
	t1[1] = m1[1];
	t1[2] = m1[2];
	t1[3] = m1[3];

	//--------------------------------------------------------------------------------------//

	//P4w8



	P4w8_1[0] = t1[3];
	P4w8_1[1] = t1[0];
	P4w8_1[2] = t1[1];
	P4w8_1[3] = t1[2];
	P4w8_1[4] = t1[1];
	P4w8_1[5] = t1[2];
	P4w8_1[6] = t1[3];
	P4w8_1[7] = t1[0];

	//--------------------------------------------------------------------------------------//

	//XoR



	for (m = 0; m<8; m++)
	{
		Xor1[m] = (P4w8_1[m] + P10w8kl1[m]) % 2;
		//printf("Xor1 to: %i\n",Xor1[m]);
	}

	//--------------------------------------------------------------------------------------//

	//DZIELENIE PRZED SBOX



	sb0[0] = Xor1[0];
	sb0[1] = Xor1[1];
	sb0[2] = Xor1[2];
	sb0[3] = Xor1[3];

	sb1[0] = Xor1[4];
	sb1[1] = Xor1[5];
	sb1[2] = Xor1[6];
	sb1[3] = Xor1[7];

	//--------------------------------------------------------------------------------------//

	//ZABAWA SBOXAMI


	XP0[0] = 0;
	XP0[1] = 0;

	wiersz = (sb0[0] * 2) + (sb0[3]);
	kolumna = (sb0[1] * 2) + (sb0[2]);

	XP0[1] = SBOX1[kolumna][wiersz] % 2;
	XP0[0] = (SBOX1[kolumna][wiersz] - XP0[1]) / 2;

	//printf("XP0 0 to: %i\n",XP0[0]);
	//printf("XP0 1 to: %i\n",XP0[1]);


	XP1[0] = 0;
	XP1[1] = 0;

	wiersz = (sb1[0] * 2) + (sb1[3]);
	kolumna = (sb1[1] * 2) + (sb1[2]);

	XP1[1] = SBOX2[kolumna][wiersz] % 2;
	XP1[0] = (SBOX2[kolumna][wiersz] - XP1[1]) / 2;

	//printf("XP1 0 to: %i\n",XP1[0]);
	//printf("XP1 1 to: %i\n",XP1[1]);

	//--------------------------------------------------------------------------------------//


	C4[0] = XP0[0];
	C4[1] = XP0[1];
	C4[2] = XP1[0];
	C4[3] = XP1[1];

	P4[0] = C4[1];
	P4[1] = C4[3];
	P4[2] = C4[2];
	P4[3] = C4[0];

	printf("Z SBOXOW PIERWSZEJ RUNDY: ");
	for (m = 0; m<4; m++)
	{
		printf("%i", P4[m]);
	}
	printf("\n");

	//--------------------------------------------------------------------------------------//

	//Xor

	for (m = 0; m<4; m++)
	{
		XORM0[m] = (P4[m] + t0[m]) % 2;
		//printf("XORM0 to: %i\n",XORM0[m]);
	}

	//--------------------------------------------------------------------------------------//

	//LACZENIE KLUCZ RUNDY PIERWSZEJ


	K1[0] = XORM0[0];
	K1[1] = XORM0[1];
	K1[2] = XORM0[2];
	K1[3] = XORM0[3];
	K1[4] = t1[0];
	K1[5] = t1[1];
	K1[6] = t1[2];
	K1[7] = t1[3];

	printf("SZYFROGRAM RUNDY 1: ");
	for (m = 0; m<8; m++)
	{
		printf("%i", K1[m]);
	}
	printf("\n");


	PO[0] = K1[3];
	PO[1] = K1[0];
	PO[2] = K1[2];
	PO[3] = K1[4];
	PO[4] = K1[6];
	PO[5] = K1[1];
	PO[6] = K1[7];
	PO[7] = K1[5];

	printf("SZYFROGRAM KONCOWY TO: ");

	for (m = 0; m<8; m++)
	{
		printf("%i", PO[m]);
	}
	printf("\n");


	//--------------------------------------------------------------------------------------//

	return 0;
}
