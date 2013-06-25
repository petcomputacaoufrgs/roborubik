// ROBO RUBIK - CONTROLE DE MOVIMENTOS - CÓDIGO ARDUINO //

// ------------ ÁREA DE DEFINES ------------

// posições dos braços
#define ESQ_POS1 2
#define ESQ_POS2 3
#define ESQ_POS3 4
#define ESQ_POS4 5

#define DIR_POS1 6
#define DIR_POS2 7
#define DIR_POS3 8
#define DIR_POS4 9

// controle das garras
#define ESQ_ABRE 10
#define ESQ_FECHA 11

#define DIR_ABRE 12
#define DIR_FECHA 13

// retorno de estado
#define ESQ_ACK A0
#define DIR_ACK A1

// outras constantes
#define ESQUERDO 0
#define DIREITO 1

#define ABERTO HIGH
#define FECHADO LOW

#define POSICAO1 1
#define POSICAO2 2
#define POSICAO3 3
#define POSICAO4 4



// ------------ ÁREA DE VARIÁVEIS ------------

int posicaoAtualEsq, posicaoAtualDir;
int bracoSerial, posicaoSerial, garraSerial;
int esqAckTemp, dirAckTemp;


// ------------ INICIALIZAÇÃO ------------

void setup ()
{
	// habilitando comunicação serial
	Serial.begin (9600);
	
	// setando entradas e saídas
	pinMode (ESQ_POS1,OUTPUT);
	pinMode (ESQ_POS2,OUTPUT);
	pinMode (ESQ_POS3,OUTPUT);
	pinMode (ESQ_POS4,OUTPUT);
	
	pinMode (DIR_POS1,OUTPUT);
	pinMode (DIR_POS2,OUTPUT);
	pinMode (DIR_POS3,OUTPUT);
	pinMode (DIR_POS4,OUTPUT);
	
	pinMode (ESQ_ABRE,OUTPUT);
	pinMode (ESQ_FECHA,OUTPUT);
	
	pinMode (DIR_ABRE,OUTPUT);
	pinMode (DIR_FECHA,OUTPUT);
	
	pinMode (ESQ_ACK,INPUT); //analógico
	pinMode (DIR_ACK,INPUT); //analógico
	
	// setando estado inicial
	
	setEsq (POSICAO1, FECHADO);
	setDir (POSICAO2, FECHADO);
	
	posicaoAtualEsq = POSICAO1;
	posicaoAtualDir = POSICAO2;
	
	esqAckTemp = 1;
	dirAckTemp = 1;
}

// ------------ MAIN ------------

void loop ()
{	
	if (Serial.available())
		{
			bracoSerial = Serial.read();
			posicaoSerial = Serial.read();
			garraSerial = Serial.read();
			movimento (bracoSerial, posicaoSerial, garraSerial);
			
		}
}

// ------------ MOVIMENTOS GERAIS ------------
void movimento (int braco, int posicao, int garra)
{
	if (braco == ESQUERDO)
		setEsq (posicao, garra);
	else if (braco == DIREITO)
		setDir (posicao, garra);
}

int setEsq (int posicao, int garra)
{
	switch (posicao)
	{
		case POSICAO1:
			garraESQ (garra);
			esqPOS1 ( );
			break;
		case POSICAO2:
			garraESQ (garra);
			esqPOS2 ( );
			break;
		case POSICAO3:
			garraESQ (garra);
			esqPOS3 ( );
			break;
		case POSICAO4:
			garraESQ (garra);
			esqPOS4 ( );
			break;
					
	}
}

int setDir (int posicao, int garra)
{
	switch (posicao)
	{
		case POSICAO1:
			garraDIR (garra);
			dirPOS1 ( );
			break;
		case POSICAO2:
			garraDIR (garra);
			dirPOS2 ( );
			break;
		case POSICAO3:
			garraDIR (garra);
			dirPOS3 ( );
			break;
		case POSICAO4:
			garraDIR (garra);
			dirPOS4 ( );
			break;
					
	}
}

// ------------ MOVIMENTO DE BRACO ------------


//braço esquerdo
void esqPOS1 ( )
{	
	switch (posicaoAtualEsq)
	{
		case POSICAO1:
			break;
		case POSICAO2:
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,HIGH);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO2;
			break;
		case POSICAO3:
			esqPOS2 ();
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,HIGH);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO3;
			break;
		case POSICAO4:
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,HIGH);
			posicaoAtualEsq = POSICAO4;
			break;
					
	}
	
	esqAckTemp = leituraAck (ESQUERDO);
	while ((esqAckTemp) != 1)
	{
	};	
}
////
void esqPOS2 ( )
{
	switch (posicaoAtualEsq)
	{
		case POSICAO1:
			digitalWrite (ESQ_POS1,HIGH);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO1;
			break;
		case POSICAO2:
			break;
		case POSICAO3:
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,HIGH);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO3;
			break;
		case POSICAO4:
			esqPOS1 ();
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,HIGH);
			posicaoAtualEsq = POSICAO4;
			break;
					
	}
	esqAckTemp = leituraAck (ESQUERDO);
	while ((esqAckTemp) != 1)
	{
	};
}
////
void esqPOS3 ( )
{
	switch (posicaoAtualEsq)
	{
		case POSICAO1:
			esqPOS2 ();
			digitalWrite (ESQ_POS1,HIGH);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO1;
			break;
		case POSICAO2:
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,HIGH);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO2;
			break;
		case POSICAO3:
			break;
		case POSICAO4:
			esqPOS2 ();
			esqPOS1 ();
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,HIGH);
			posicaoAtualEsq = POSICAO4;
			break;
					
	}
	esqAckTemp = leituraAck (ESQUERDO);
	while ((esqAckTemp) != 1)
	{
	};
}
////
void esqPOS4 ( )
{
	switch (posicaoAtualEsq)
	{
		case POSICAO1:
			digitalWrite (ESQ_POS1,HIGH);
			digitalWrite (ESQ_POS2,LOW);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO1;
			break;
		case POSICAO2:
			esqPOS1 ();
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,HIGH);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO2;
			break;
		case POSICAO3:
			esqPOS1 ();
			esqPOS2 ();
			digitalWrite (ESQ_POS1,LOW);
			digitalWrite (ESQ_POS2,HIGH);
			digitalWrite (ESQ_POS3,LOW);
			digitalWrite (ESQ_POS4,LOW);
			posicaoAtualEsq = POSICAO3;
			break;
		case POSICAO4:
			break;
					
	}
	esqAckTemp = leituraAck (ESQUERDO);
	while ((esqAckTemp) != 1)
	{
	};
}

//braço direito
void dirPOS1 ( )
{
	switch (posicaoAtualDir)
	{
		case POSICAO1:
			break;
		case POSICAO2:
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,HIGH);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO2;
			break;
		case POSICAO3:
			dirPOS2 ();
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,HIGH);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO3;
			break;
		case POSICAO4:
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,HIGH);
			posicaoAtualDir = POSICAO4;
			break;
					
	}
	dirAckTemp = leituraAck (DIREITO);
	while ((dirAckTemp) != 1)
	{
	};
}
////
void dirPOS2 ( )
{
	switch (posicaoAtualDir)
	{
		case POSICAO1:
			digitalWrite (DIR_POS1,HIGH);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO1;
			break;
		case POSICAO2:
			break;
		case POSICAO3:
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,HIGH);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO3;
			break;
		case POSICAO4:
			dirPOS1 ();
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,HIGH);
			posicaoAtualDir = POSICAO4;
			break;
					
	}
	dirAckTemp = leituraAck (DIREITO);
	while ((dirAckTemp) != 1)
	{
	};
}
////
void dirPOS3 ( )
{
	switch (posicaoAtualDir)
	{
		case POSICAO1:
			dirPOS2 ();
			digitalWrite (DIR_POS1,HIGH);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO1;
			break;
		case POSICAO2:
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,HIGH);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO2;
			break;
		case POSICAO3:
			break;
		case POSICAO4:
			dirPOS2 ();
			dirPOS1 ();
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,HIGH);
			posicaoAtualDir = POSICAO4;
			break;
					
	}
	dirAckTemp = leituraAck (DIREITO);
	while ((dirAckTemp) != 1)
	{
	};
}
////
void dirPOS4 ( )
{
	switch (posicaoAtualDir)
	{
		case POSICAO1:
			digitalWrite (DIR_POS1,HIGH);
			digitalWrite (DIR_POS2,LOW);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO1;
			break;
		case POSICAO2:
			dirPOS1 ();
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,HIGH);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO2;
			break;
		case POSICAO3:
			dirPOS1 ();
			dirPOS2 ();
			digitalWrite (DIR_POS1,LOW);
			digitalWrite (DIR_POS2,HIGH);
			digitalWrite (DIR_POS3,LOW);
			digitalWrite (DIR_POS4,LOW);
			posicaoAtualDir = POSICAO3;
			break;
		case POSICAO4:
			break;
					
	}
	dirAckTemp = leituraAck (DIREITO);
	while ((dirAckTemp) != 1)
	{
	};
}



// ------------ MOVIMENTO DE GARRA ------------
void garraESQ (int garra)
{
	if (garra == ABERTO)
		esqABRE ();
	else if (garra == FECHADO)
		esqFECHA ();
}

void garraDIR (int garra)
{
	if (garra == ABERTO)
		dirABRE ();
	else if (garra == FECHADO)
		dirFECHA ();
}

void esqABRE ()
{
	digitalWrite (ESQ_ABRE,HIGH);
	digitalWrite (ESQ_FECHA,LOW);
}

void esqFECHA ()
{
	digitalWrite (ESQ_ABRE,LOW);
	digitalWrite (ESQ_FECHA,HIGH);
}

void dirABRE ()
{
	digitalWrite (DIR_ABRE,HIGH);
	digitalWrite (DIR_FECHA,LOW);
}

void dirFECHA ()
{
	digitalWrite (DIR_ABRE,LOW);
	digitalWrite (DIR_FECHA,HIGH);
}


// ------------ FUNÇÕES AUXILIARES ------------

int leituraAck (int braco)
{
	int leitura;
	if (braco == ESQUERDO)
		{
			leitura = analogRead (ESQ_ACK);
			if (leitura > 900) // valor de sinal aceitável para se interpretar como 1 lógico
				return 1;
			else
				return 0;
		}
	else if (braco == DIREITO)
		{
			leitura = analogRead (DIR_ACK);
			if (leitura > 900) // valor de sinal aceitável para se interpretar como 1 lógico
				return 1;
			else
				return 0;
		}
}


