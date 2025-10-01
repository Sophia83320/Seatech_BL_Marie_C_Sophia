/* 
 * File:   Robot.h
 * Author: E306-PC2
 *
 * Created on 1 octobre 2025, 08:46
 */

#ifndef ROBOT_H
#define ROBOT_H



typedef struct robotStateBITS {
union {
struct {
unsigned char taskEnCours;
float vitesseGaucheConsigne;
float vitesseGaucheCommandeCourante;
float vitesseDroiteConsigne;
float vitesseDroiteCommandeCourante;
float acceleration;

};
};
} ROBOT_STATE_BITS;
extern volatile ROBOT_STATE_BITS robotState;
void PWMUpdateSpeed();
void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur);
#endif /* ROBOT_H */

