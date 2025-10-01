#include "Robot.h"
#include "PWM.h"
#include <xc.h>
#include "IO.h"
#include "Toolbox.h"

volatile ROBOT_STATE_BITS robotState;

void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur){
    if(moteur==MOTEUR_GAUCHE){
        robotState.vitesseGaucheConsigne=vitesseEnPourcents;
    }
    else if(moteur==MOTEUR_DROIT){
        robotState.vitesseDroiteConsigne=vitesseEnPourcents;
    }
}

//double talon = 50;

void PWMUpdateSpeed()
{
// Cette fonction est appelee sur timer et permet de suivre des rampes d acceleration
if (robotState.vitesseGaucheCommandeCourante < robotState.vitesseGaucheConsigne)
    robotState.vitesseGaucheCommandeCourante = Min(
    robotState.vitesseGaucheCommandeCourante + robotState.acceleration,
    robotState.vitesseGaucheConsigne);
if (robotState.vitesseGaucheCommandeCourante > robotState.vitesseGaucheConsigne)
    robotState.vitesseGaucheCommandeCourante = Max(
    robotState.vitesseGaucheCommandeCourante - robotState.acceleration,
    robotState.vitesseGaucheConsigne);
if (robotState.vitesseGaucheCommandeCourante > 0)
{
    PDC1 = robotState.vitesseGaucheCommandeCourante * PWMPER + talon;
    SDC1 = talon;
}
else
{
    PDC1 = talon;
    SDC1 = -robotState.vitesseGaucheCommandeCourante * PWMPER + talon;
}
if (robotState.vitesseDroiteCommandeCourante < robotState.vitesseDroiteConsigne)
    robotState.vitesseDroiteCommandeCourante = Min(
    robotState.vitesseDroiteCommandeCourante + robotState.acceleration,
    robotState.vitesseDroiteConsigne);
if (robotState.vitesseDroiteCommandeCourante > robotState.vitesseDroiteConsigne)
    robotState.vitesseDroiteCommandeCourante = Max(
    robotState.vitesseDroiteCommandeCourante - robotState.acceleration,
    robotState.vitesseDroiteConsigne);
if (robotState.vitesseDroiteCommandeCourante >= 0)
{
    PDC2 = robotState.vitesseDroiteCommandeCourante * PWMPER + talon;
    SDC2 = talon;
}
else
{
    PDC2 = talon;
    SDC2 = -robotState.vitesseDroiteCommandeCourante * PWMPER + talon;
}
}

