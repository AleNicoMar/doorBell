//Sonido del timbre

void ring(){//El sonido por ahora será este, estaría bueno controlar el volumen del buzzer para reproducir mejores sonidos.
  for(int i=0;i<=1; i++){
    tone(buzzerPin,2048,50);
    if(i==0){
      delay(100);
      tone(buzzerPin,4096,50);
    }
    delay(250);
  }
}

//EVENTO: Botón del timbre presionado.
bool buttonState = LOW;

void doorBell(){//Cuando tocan el timbre, arranca ring() a hacerlo sonar.
  buttonState = digitalRead(buttonPin);
  if(buttonState != HIGH){
    ring();
  }
}
