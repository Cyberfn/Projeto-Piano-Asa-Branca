const int pino_buzzer = 10; // pino onde o buzzer está conectado
const int pino_botao = 2;
const int tempo = 1000;

// Frequencias de cada nota musical
const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi
const int f = 349; // Fá
const int g = 391; // Sol
const int a = 440; // Lá
const int b = 493; // Si

int notas[] = {c, d, e, g, g, e, f, f, 0, c, d, e, g, g, f, e, 0, c, c, d, e, g, 0, g, f, e, c, f, 0, f, e, d, d, e, 0, d, d, c, c, 0};
int tempos[] = {4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 1, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 1, 6};
int tamanho = 0, i;

void setup() {
  pinMode(pino_botao, INPUT_PULLUP);
  pinMode(pino_buzzer, OUTPUT); // configura o pino com o buzzer como saída
  tamanho = sizeof(notas) / 2;
   for (i = 0; i < tamanho; i++) {
    tempos[i] = tempo/tempos[i];
   }
}
void loop() {
  bool estado_botao = digitalRead(pino_botao);
  if (estado_botao == LOW) {
    for (i = 0; i < tamanho; i++) {
      if (notas[i] == 0) {
        noTone(pino_buzzer);
        delay(tempos[i]);
      }
      else {
        tone(pino_buzzer, notas[i]);
        delay(tempos[i]);
      }
    }
  }
}