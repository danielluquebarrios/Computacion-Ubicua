# Laboratorio 1 — Pulsador y LED temporizado (Arduino)

## Descripción

Circuito con un pulsador y un LED: al presionar el pulsador, el LED se enciende
durante 5 segundos y luego se apaga automáticamente. Incluye una espera simple
tipo antirrebote mientras el pulsador permanece presionado.

## Enlaces del proyecto

- **Tinkercad:** https://www.tinkercad.com/things/eg6z3EYDa0c-laboratorio-1
- **Velxio:** https://velxio.dev/project/9ca759ad-83a2-4111-afca-6b100423d067
- **Wokwi:** https://wokwi.com/projects/474631246062386177

## Conexiones

| Componente | Pin Arduino |
|---|---|
| Pulsador | 2 (INPUT) |
| LED | 3 (OUTPUT) |

## Código (sketch.ino)

```cpp
/*
	Capitulo 3 de Arduino desde cero en Español
	Tercer programa que al presionarse el pulsador enciende LED por 5 segundos y luego
	apaga solo.

	Autor: bitwiseAr
*/

int PULSADOR = 2;
int LED = 3;

void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {

  while (digitalRead(PULSADOR) == LOW) {   // espera infinitamente hasta que se presione el pulsador
  }

  digitalWrite(LED, HIGH);                 // enciende LED
  delay(5000);                             // espera de 5 seg.
  digitalWrite(LED, LOW);                  // apaga LED

  while (digitalRead(PULSADOR) == HIGH) {  // espera como funcion antirebote simple
  }

}
```

## Funcionamiento

1. El pin del pulsador se configura como entrada y el del LED como salida, iniciando en `LOW`.
2. El programa queda en espera bloqueante mientras el pulsador no esté presionado.
3. Al detectar la pulsación, enciende el LED, espera 5000 ms (`delay`) y lo apaga.
4. Un segundo bucle de espera evita que se repita la acción mientras el botón siga presionado (antirrebote simple por software).
