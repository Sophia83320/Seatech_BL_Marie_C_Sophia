/* 
 * File:   main.c
 * Author: E306-PC2
 *
 * Created on September 29, 2025, 2:35 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"



int main(void) {
    //Initialisation oscillateur
    InitOscillator();
    InitTimer23();
    InitTimer1();
    //Configuration des input et output (IO)
    InitIO();
    LED_BLANCHE_1 = 1;
    LED_BLEUE_1 = 1;
    LED_ORANGE_1 = 1;
    LED_ROUGE_1 = 1;
    LED_VERTE_1 = 1;

    //Boucle Principale
    while (1) {
//        LED_BLANCHE_1 = !LED_BLANCHE_1;
//        LED_BLEUE_1 = !LED_BLEUE_1;
//        LED_ORANGE_1 = !LED_ORANGE_1;
    } // fin main
}

