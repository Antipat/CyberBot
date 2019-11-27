int p=A0;


void setup() {
  pinMode(p, OUTPUT);

}

void loop() {
  
tone(p, 261);
    delay(500);

    
    tone(p, 293);
      delay(500);
      
      tone(p, 329);
      delay(500);

          tone(p,349 );
      delay(500);  
      
        tone(p,392);
      delay(500); 
       
      tone(p, 440);
      delay(500);

      tone(p,466 );
      delay(500);  

      tone(p,494 );
      delay(500);  
      
     tone(p, -1);
     delay(1000);
}
