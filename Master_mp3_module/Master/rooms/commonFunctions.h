/*
 * commonFunctions.h
 *
 * Created: 1/26/2020 12:02:57 AM
 *  Author: Rishav
 */ 

#ifndef COMMONFUNCTIONS_H_
#define COMMONFUNCTIONS_H_

unsigned long toMillis(unsigned long min, unsigned long sec){
	return (((min*60+sec)*(unsigned long)1000));
}

void chooseLanguage(uint8_t volume){
	
	while (1){
		if(!(PINA & _BV(NEPALI_LANGUAGE_PIN))){
			ampPlay(NEPALI);
			break;
		}
		else if(!(PINA & _BV(ENGLISH_LANGUAGE_PIN))){
			ampPlay(ENGLISH);
			break;
		}
		else if(!(PINA & _BV(HINDI_LANGUAGE_PIN))){
			ampPlay(HINDI);
			break;
		}
	}
}

#endif /* COMMONFUNCTIONS_H_ */