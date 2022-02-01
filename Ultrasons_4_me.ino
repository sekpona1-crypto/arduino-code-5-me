/* 
 * Code d'exemple pour un capteur à ultrasons HC-SR04.
 */
/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
 int LED1= 7;
 int LED2 =6;
 int LED3 =5;
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

/** Fonction setup() */
void setup() {

   
  /* Initialise le port série */
  Serial.begin(115200);
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
    pinMode(12, OUTPUT);
}
 
/** Fonction loop() */
void loop() {
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float d = measure / 2.0 * SOUND_SPEED;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print(F("Distance: "));
  Serial.println(d/10);

 if (0<d<10){
 analogWrite(LED1,255);    // Rouge 
analogWrite(LED2,0);    // Vert 
analogWrite(LED3,0);    // Bleu
 tone (12, 600); // allume le buzzer actif arduino
delay(1000);
     
 }
 else if (11<d<30){
  analogWrite(LED1,0); 
  delay(500);// Rouge 
analogWrite(LED3,255);    // Vert 
analogWrite(LED2,0);    // Bleu
tone(12, 900); // allume le buzzer actif arduino
delay(1000);
 }
 else if (31<d<100){
   analogWrite(LED1,0);    // Rouge 
analogWrite(LED3,255);    // Vert 
analogWrite(LED2,0);    // Bleu
delay(1000);
 }
  else{
  analogWrite(LED1,0);    // Rouge 
analogWrite(LED2,0);    // Vert 
analogWrite(LED3,0);    // Bleu

delay(1000);
 }
  noTone(12);  // désactiver le buzzer actif arduino
   delay(500);/* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  
}
