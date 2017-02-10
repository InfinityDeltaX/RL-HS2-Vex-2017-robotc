#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    gyro1,          sensorGyro)
#pragma config(Sensor, in2,    armpot,         sensorPotentiometer)
#pragma config(Sensor, in3,    frontline,      sensorLineFollower)
#pragma config(Sensor, in4,    leftline,       sensorLineFollower)
#pragma config(Sensor, in5,    centerline,     sensorLineFollower)
#pragma config(Sensor, in6,    rightline,      sensorLineFollower)
#pragma config(Sensor, in7,    clawpot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  led1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  led2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  led3,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  fronttouch,     sensorTouch)
#pragma config(Sensor, dgtl5,  lefttouch,      sensorTouch)
#pragma config(Sensor, dgtl6,  righttouch,     sensorTouch)
#pragma config(Sensor, dgtl7,  sonar1,         sensorSONAR_mm)
#pragma config(Sensor, dgtl9,  sonar2,         sensorSONAR_mm)
#pragma config(Sensor, dgtl11, autonflip,      sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           armmotor2R,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           drivemotor1,   tmotorVex393_MC29, PIDControl, encoderPort, I2C_1)
#pragma config(Motor,  port3,           drivemotor2,   tmotorVex393_MC29, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port4,           drivemotor3,   tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
#pragma config(Motor,  port5,           drivemotor4,   tmotorVex393_MC29, PIDControl, encoderPort, I2C_4)
#pragma config(Motor,  port6,           armmotor1R,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armmotor1L,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawmotorL,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawmotorR,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          armmotor2L,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)
#pragma systemFile

// Select Download method as "competition"
#pragma competitionControl(Competition)


//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "GyroLib2.c"

void movementControl();
void moveRelative(int forwardsbackwardsPower, int sidewaysPower, int rotationPower);
void driveSet(int aPower, int bPower, int cPower, int dPower);
//void moveAbsoluteWithRotation(int fieldX, int fieldY, float targetfieldAngle, int speed);
void moveAbsolute(int fieldX, int fieldY, int speed);
float computeAngleFromR(int r);
void movePolarRelative(float angle, int speed);
void addConcurrentYawAnglePerSecond(float angle);
void addConcurrentYaw(int power);
void resetAllIMEs();
void functionControl();
void alternateBlinkers();
void stopDrive();
void testPolarDrive();
float computeAngleFromDeltas(int xdelta, int ydelta);
void computeLocationFromSonar(int sensor1, int sensor2, int robotwidth, float gyro);
float degToRad(float degrees);
void sensor_init();
int encoderTicksToMM(int ticks);
void computePosition();
float getGyroAngle();
void updatePositionFromWheelEncoders();
void updateLineSensorLocation();
void snapPositionToFrontLineSensor();
void debug();
void armSetSpeed(int speed);
void armUp();
void armDown();
void armStop();
void setArmDownPos();
void setArmUpPos();
//void moveAndRotateControl();
void moveAndRotateGyro(int verticalstick, int horizontalstick, int rotateSpeed);
void moveAndRotateRaw(int verticalstick, int horizontalstick, int rotateSpeed);
void updateTouchSensorLocation();
void movePolarRelativeWithYaw(float angle, int speed, int rotation);
float adjustRadianAngle(float ret);
int deadzoneCompensate(int in);
void setArmPos(int target);
void armControl();
void clawControl();
void clawSetOpening();
void clawSetClosing();
void setClawSpeed(int speed);
void clawSetStop();
void gyroControl();
void hardResetGyro();
void softResetGyro();
void alignWithLineIncr();
void setAbsoluteHeading(float heading);
int maxabs(int a, int b);
void trackingControl();
void toggleArm();
void toggleClaw();
void setClawPos(int target);
void setClawOpenPos();
void setClawClosedPos();
void automaticClaw();
void actuatorRotate();
float minfloatabs(float a, float b);
void clawSetClosingSlow();
void clawSetOpeningSlow();

int headingFindTurnSpeed = 64;
float headingTolerance = 2*PI/72.0; //5 degrees

int motorEncoder1Offset = 0;
int motorEncoder2Offset = 0;
int motorEncoder3Offset = 0;
int motorEncoder4Offset = 0;

int currentPositionX = 0;
int currentPositionY = 0;
int currentPositionR = 0;

int fieldWidth = 3568;
int fieldHeight = fieldWidth/2;
int firstLinePosition = 880;
int secondLinePosition = 1645;
int mmPerWheelTurn = 327;
int encoderTicksPerTurn = 627;
int lineThreshhold = 1700;

int armpotlowval = 100;
int armpothighval = 2250;
int armSpeedGoingUp = 128;
int armSpeedGoingDown = 64;
int ARM_MOVING_UP = 1;
int ARM_MOVING_DOWN = -1;
int ARM_STOP = 0;
int ARM_AUTO = 2;
int ARM_NO_TARGET = -1;
int targetArmPosition = -1;
int mostRecentArmInstruction = 0;

int clawSpeed = 70;
int clawpotopenval = 2000;//300 is the most allowed mechanically
int clawpotclosedval = 3000;
int clawState = 49;
int CLAW_OPENING = 1;
int CLAW_CLOSING = -1;
int CLAW_STOP = 0;
int CLAW_AUTO = 2;
int CLAW_NO_TARGET = -1;
float clawHighPowerCutoffOpening = 0.7;
float clawHighPowerCutoffClosing = 0.7;
int mostRecentClawInstruction = 0;
int targetClawPosition = -1;

int robotwidthMM =  450;
int robotlengthMM = 450;
int deadzone_width = 25;

int actuator_rotation_state = 0;

int permissibleAbsolutePositioningErrorMM = 10;

int wheelTurnsPerRobotTurn = 3;
bool ledflashconfig = false;

float recentGyro = 0;
float recentGyro2 = 0;
float gyroMountingAngle = 0; //-1 * PI/2;
float gyroOffset = gyroMountingAngle;

int BUTTON_6U_STATE = 0;
int BUTTON_6D_STATE = 0;
int BUTTON_5U_STATE = 0;

int clawNewRecent = 0;

int clawIdleSpeedClosing = 15;
int clawIdleSpeedOpening = 15;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

task functionControlAuto(){
	while(true) {
		functionControl();
		automaticClaw();
	}
}

task autonomous()
{

	int SIDE_RIGHT = 1;
	int SIDE_LEFT = -1;

	int side = 0;

	if(SensorValue[dgtl11]) side = SIDE_RIGHT;
	else side = SIDE_LEFT;

	//int side = SIDE_LEFT;

	startTask(functionControlAuto);

	//Autonomous code
	int movespeed = 110;
	float delayfactor = 1.15;
	int stoppingDelay = 800;

	float armPercentageSide = 0.9;
	float armPercentageMiddle = 0.83;

	int backFromFenceTime = 1000;
	int sidewaysAtFenceTime = 1700;
	int fromStartToFenceTime = 2100;

	nMotorPIDSpeedCtrl[drivemotor1] = RegIdle;
	nMotorPIDSpeedCtrl[drivemotor2] = RegIdle;
	nMotorPIDSpeedCtrl[drivemotor3] = RegIdle;
	nMotorPIDSpeedCtrl[drivemotor4] = RegIdle;

	wait1Msec(200);

	moveRelative(127, 0, 0);
	wait1Msec(500);
	moveRelative(-127, 0, 0);
	wait1Msec(1000);
	stopDrive();

	nMotorPIDSpeedCtrl[drivemotor1] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[drivemotor2] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[drivemotor3] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[drivemotor4] = mtrSpeedReg;

	sensor_init();

	wait1Msec(1500);

	setArmPos((armPercentageSide * (armpothighval - armpotlowval)) + armpotlowval); //deploy

	setClawOpenPos();


	setAbsoluteHeading(0);
	moveRelative(movespeed, side * ( - movespeed / 3.0), 0);
	//moveAndRotateGyro(movespeed, side * ( - movespeed / 3.0), 0);
	wait1Msec(fromStartToFenceTime*delayfactor*1.12);
	stopDrive();
	wait1Msec(stoppingDelay); //drive up to fence; push stars over.

	setAbsoluteHeading(0);
	moveRelative(-1 * movespeed, 0, 0); //drive back.
	//moveAndRotateGyro(-1 * movespeed, 0, 0);
	wait1Msec(backFromFenceTime*delayfactor);
	stopDrive();
	wait1Msec(stoppingDelay);

	setArmPos((armPercentageMiddle * (armpothighval - armpotlowval)) + armpotlowval);
	wait1Msec(1000);

	setAbsoluteHeading(0);
	moveRelative(0, side*movespeed, 0); //drive sideways
	//moveAndRotateGyro(0, side*movespeed, 0);
	wait1Msec(sidewaysAtFenceTime*delayfactor);
	stopDrive();
	wait1Msec(stoppingDelay);

	setAbsoluteHeading(0);
	moveRelative(movespeed, 0, 0); //drive forwards to hit off middle stars
	//moveAndRotateGyro(movespeed, 0, 0);
	wait1Msec(backFromFenceTime*delayfactor);
	stopDrive();
	wait1Msec(stoppingDelay);

	/*
	//moveRelative(-1 * movespeed, 0, 0); //drive back.
	wait1Msec(backFromFenceTime*delayfactor);
	stopDrive();
	wait1Msec(stoppingDelay);

	//moveRelative(0, side*movespeed, 0); //drive sideways
	setArmPos((armPercentageSide * (armpothighval - armpotlowval)) + armpotlowval);
	wait1Msec(sidewaysAtFenceTime*delayfactor);
	stopDrive();
	wait1Msec(stoppingDelay);

	//moveRelative(movespeed, 0, 0); //drive forwards to hit off middle stars
	wait1Msec(backFromFenceTime*delayfactor);
	stopDrive();
	//wait1Msec(stoppingDelay);

	//setAbsoluteHeading(degreesToRadians(15));
	//smoveAndRotateGyro();
	*/
}

task usercontrol()
{

	sensor_init();
	//debug();

	nMotorPIDSpeedCtrl[drivemotor1] = RegIdle;
	nMotorPIDSpeedCtrl[drivemotor2] = RegIdle;
	nMotorPIDSpeedCtrl[drivemotor3] = RegIdle;
	nMotorPIDSpeedCtrl[drivemotor4] = RegIdle;

	while(true) {
		debug();
		movementControl();
		functionControl();
		//computePosition();
	}
}

void debug(){
	/*while(VexRT[Btn8U]==1){
		writeDebugStreamLine("%d \n", (sensorValue[centerline]));
		int a = SensorValue[armpot];
	}
	*/
}

void functionControl(){
	armControl();
	clawControl();
	gyroControl();
	trackingControl();
}

void sensor_init(){
	GyroInit(in1);
	resetAllIMEs();
}

//------------CONTROL--------------

void movementControl(){
	int rotationPower = deadzoneCompensate(vexRT[Ch4]);
	int forwardsbackwardsPower = deadzoneCompensate(vexRT[Ch2]);
	int sidewaysPower = deadzoneCompensate(-1 * vexRT[Ch1]);

	if(false && vexRT[Btn5D]){ //DISABLED
		moveRelative(128, 0, rotationPower);
	} else if (false /*vexRT[Btn5U]*/ ){
		moveAndRotateRaw(forwardsbackwardsPower, sidewaysPower, rotationPower);
	} else { //default
		moveRelative(forwardsbackwardsPower, sidewaysPower, rotationPower);
	}
}

void gyroControl(){
	if(vexRT[Btn8L]) softResetGyro();
	if(vexRT[Btn8R]) hardResetGyro();
}

void trackingControl(){
	while(vexRT[Btn8D]){
		alignWithLineIncr();
	}
	if(vexRT[Btn8U]) {
		setAbsoluteHeading(0);
	}
}

//------------TESTING--------------

void testPolarDrive(){
		movePolarRelative(0, 100);
		delay(1000);
		movePolarRelative(PI/2, 100);
		delay(1000);
		movePolarRelative(PI, 100);
		delay(1000);
		movePolarRelative(3*PI/2, 100);
		delay(1000);
		stopDrive();
}

//------------MOVING--------------

void moveRelative(int forwardsbackwardsPower, int sidewaysPower, int rotationPower){
	//128 should output 128s.
	//128-128 needs to output something reasonable.
	int a = -1 * forwardsbackwardsPower + -1 * sidewaysPower + rotationPower;
	int b = forwardsbackwardsPower + -1 * sidewaysPower + rotationPower;
	int c = forwardsbackwardsPower + sidewaysPower + rotationPower;
	int d = -1 * forwardsbackwardsPower + sidewaysPower + rotationPower;

	int max = maxabs(maxabs(a, b), maxabs(c, d));
	if(abs(max) > 128) {
		float ratio = 127/(float) abs(max) - 0.02;
		//moveRelative(forwardsbackwardsPower*ratio, sidewaysPower*ratio, rotationPower*ratio);

		a = a*ratio;
		b = b*ratio;
		c = c*ratio;
		d = d*ratio;
	}

	//writeDebugStreamLine("%d, %d, %d, %d", a, b, c, d);

	//driveSet(a/2, b/2, c/2, d/2);
	driveSet(a, d, c, b);
}

void stopDrive(){
	driveSet(0, 0, 0, 0);
}

void driveSet(int aPower, int bPower, int cPower, int dPower){
	motor[drivemotor1] = aPower;
	motor[drivemotor2] = bPower;
	motor[drivemotor3] = cPower;
	motor[drivemotor4] = dPower;

	//updatePositionFromWheelEncoders();
}

void moveAbsolute(int fieldX, int fieldY, int speed) {

	while((abs(fieldX - currentPositionX) + abs(fieldY - currentPositionY)) < permissibleAbsolutePositioningErrorMM) {
	computePosition();

	int xdelta = fieldX - currentPositionX;
	int ydelta = fieldY - currentPositionY;
	float movementAngle = computeAngleFromDeltas(xdelta, ydelta);

	int distance = sqrt(xdelta*xdelta + ydelta*ydelta);

	float startAngle = getGyroAngle();
	recentGyro = startAngle;

	movePolarRelative(speed, movementAngle - startAngle);

	}
}

void setAbsoluteHeading(float heading){ //0 -> 0. 180 -> 180. 360 -> 0. -360 -> 0. Add 180. Subtract 360s while it's too big. Subtract 180.
	float currentAngle = getGyroAngle();
	float rawdelta = heading - currentAngle;

	float delta = minfloatabs(minfloatabs(delta, delta + 2*PI), delta - 2*PI);


	int direction = 0;
	if(delta != 0) direction = (delta)/abs(delta);

	stopDrive();
	addConcurrentYaw(-1*direction*headingFindTurnSpeed);

	while(abs(delta) > headingTolerance && (delta)/abs(delta) == direction && !vexRT[Btn8L]) {
		rawdelta = heading - getGyroAngle();
		delta = minfloatabs(minfloatabs(delta, delta + 2*PI), delta - 2*PI);
		wait1Msec(10);
	}

	stopDrive();
}
/*
void moveAbsoluteWithRotation(int fieldX, int fieldY, float targetfieldAngle, int speed){
	int xdelta = fieldX - currentPositionX;
	int ydelta = fieldY - currentPositionY;

	float movementAngle = computeAngleFromDeltas(xdelta, ydelta);
	//int rdelta = fieldR - currentPositionR;

	int distance = sqrt(xdelta*xdelta + ydelta*ydelta);

	float startRAngle = computeAngleFromR(currentPositionR);
	float endRAngle = targetfieldAngle-startRAngle;

	int delayTime = distance/speed/steps*100;
	float yawAnglePerSecond = turnByAngle/delayTime*100;

	for(int i = 0; i < steps; i++){
		//movementAngle
		alternateBlinkers();
		movePolarRelative(movementAngle-currentRAngle, speed);
		addConcurrentYawAnglePerSecond(yawAnglePerSecond);
		delay(delayTime);
		currentRAngle += turnByAngle;
	}

	//int //in the same amount of time we need to complete rdelta turns.
}
*/

void moveAndRotateGyro(int verticalstick, int horizontalstick, int rotateSpeed) {
		float currentRAngle = getGyroAngle();

		float stickAngle = computeAngleFromDeltas(horizontalstick, verticalstick);
		int linearSpeed = sqrt(horizontalstick*horizontalstick + verticalstick*verticalstick);
		movePolarRelativeWithYaw(adjustRadianAngle(stickAngle-currentRAngle), linearSpeed, rotateSpeed);
		//addConcurrentYaw(rotateSpeed);
}

void moveAndRotateRaw(int verticalstick, int horizontalstick, int rotateSpeed){
		float stickAngle = computeAngleFromDeltas(horizontalstick, verticalstick);
		int linearSpeed = sqrt(horizontalstick*horizontalstick + verticalstick*verticalstick);
		movePolarRelativeWithYaw(adjustRadianAngle(stickAngle), linearSpeed, rotateSpeed);
}

void movePolarRelative(float angle, int speed){
	moveRelative(sin(angle) * speed, cos(angle) * speed, 0);
}

void movePolarRelativeWithYaw(float angle, int speed, int rotation){
	moveRelative(sin(angle) * speed, cos(angle) * speed, rotation);
}

void addConcurrentYawAnglePerSecond(float angle){
  int power = (float) angle*400.0;
  addConcurrentYaw(power);
}

void addConcurrentYaw(int power){
  driveSet(motor[drivemotor1] + power, motor[drivemotor2] + power, motor[drivemotor3] + power, motor[drivemotor4] + power);
}

//------------TRACKING--------------

void computePosition(){
	updatePositionFromWheelEncoders();
	updateLineSensorLocation();
	updateTouchSensorLocation();
}

int encoderTicksToMM(int ticks){
	return ticks*mmPerWheelTurn/encoderTicksPerTurn;
}

void updatePositionFromWheelEncoders(){ //add all the movement since the last time this function was run. Therefore, we should try to run it every time the robot turns. Used to be trackposition().

	int a = SensorValue[I2C_1];// - motorEncoder1Offset;
	int b = SensorValue[I2C_2];// - motorEncoder2Offset;
	int c = SensorValue[I2C_3];// - motorEncoder3Offset;
	int d = SensorValue[I2C_4];// - motorEncoder4Offset;

	resetAllIMEs();

	int rDist = (a + b + c + d)/4;
	int fwbDist = ( (b-rDist) + (c-rDist) ) /2 + -1 * ( (a-rDist) + (d-rDist) ) /2;
	int sideDist = ( (c-rDist) + (d-rDist) ) /2 + -1 * ( (a-rDist) + (b-rDist) ) /2;
	float angle = getGyroAngle();
	int xDist = sin(angle) * sideDist + cos(angle) * fwbDist;
	int yDist = sin(angle) * fwbDist + cos(angle) * sideDist;

	currentPositionX += encoderTicksToMM(xDist);
	currentPositionY += encoderTicksToMM(yDist);
	currentPositionR += encoderTicksToMM(rDist);
}

void computeLocationFromSonar(int sensor1, int sensor2, int robotwidth, float gyro){
    //xt and yt are the locations on the walls where the sensor ping hits.

    int length = sensor1 + sensor2 + robotwidth;
    float ratio1 = (sensor1 + robotwidth*0.5) / length;
    float ratio2 = (sensor2 + 0.5*robotwidth) / length;
    float tangyro = sin(gyro)/cos(gyro);
    float yt = sqrt(length*length / ( (float) 1 + tangyro*tangyro) );
    int y = yt - ratio1*yt;

    float xt = yt/(float) tangyro;
    int x = xt - ratio2*xt;

    //printf("ratio1: %f, ratio2: %f, length:%d, tangyro:%f, yt:%f, xt:%f, y:%d, x:%d \n", ratio1, ratio2, length, tangyro, yt, xt, y, x);

    //printf("%d should equal %f \n", length*length, xt*xt + yt*yt);

    //xreal = x;
    //yreal = y;
}

void updateSonarLocation(){
	computeLocationFromSonar(SensorValue(sonar1), sonar2, 400, SensorValue(gyro1));
}

void updateLineSensorLocation(){
	int centerLineSensorValue = SensorValue[centerline];
	if(centerLineSensorValue > lineThreshhold) {
		currentPositionY = firstLinePosition;
	}

	//can't compute front line sensor for now.

	int frontLineSensorValue = SensorValue[frontline];

	//if(frontLineSensorValue > lineThreshhold) {
	//	snapPositionToFrontLineSensor();
	//}
}

void updateTouchSensorLocation(){
	if(SensorValue[fronttouch] || SensorValue[lefttouch] || SensorValue[righttouch]) {
		float currentAngle = getGyroAngle();
		int mult = (currentAngle + (PI/4)) /(PI/2); //what quadrant, rounded down.
		float correctDirection = mult * (PI/2);
		float offsetChange = correctDirection - currentAngle;
		gyroOffset += offsetChange;
	}
}

void snapPositionToFrontLineSensor(){ //not currently in use.
	int lineMedian = (firstLinePosition + secondLinePosition) / 2;
	if(currentPositionY > lineMedian) {
		currentPositionY = secondLinePosition-robotlengthMM/2;
	} else {
		currentPositionY = firstLinePosition-robotlengthMM/2;
	}
}

void alignWithLineIncr(){
	int direction = 1;
		//connect with middle line.
		if(SensorValue[centerline] > lineThreshhold) moveRelative(32, 0, 0);
		while(SensorValue[centerline] > lineThreshhold){ //center can't see middle line yet.
			wait1Msec(10);
		}
		stopDrive();

		//rotate to see the line.
		while(SensorValue[centerline] > lineThreshhold && !(SensorValue[rightline] > lineThreshhold && SensorValue[leftline] > lineThreshhold)){ //middle but not sides.
			moveRelative(0, 0, 32*direction);
		}
		stopDrive();

		if(SensorValue[centerline] > lineThreshhold && SensorValue[rightline] > lineThreshhold && SensorValue[leftline] > lineThreshhold){
			hardResetGyro();
			//PAUSE somehow TODO
		}
}

//------------UTIL--------------

float minfloatabs(float a, float b){
	if(abs(a) > abs(b)) return b;
	else return a;
}

int maxabs(int a, int b){
	if(abs(a) >= abs(b)) return a;
	else return b;
}

float adjustRadianAngle(float ret){
	if(ret >= 2*PI) {ret = ret-2*PI;}
	if(ret < 0) {ret = ret + 2*PI;}
	return ret;
}

float computeAngleFromDeltas(int xdelta, int ydelta){
	if(xdelta==0) {xdelta = 1;}
	int factor = 1;
	//if(xdelta < 0) {factor = -1}; //must negate arctan iff x is negative
	return factor * atan2(xdelta, ydelta);
}

float computeAngleFromR(int r){
	return ( r/ ((float) encoderTicksPerTurn * wheelTurnsPerRobotTurn));
	//return 0.0;
}

float getGyroAngle(){
	float rawGyro = GyroAngleRadGet();
	float ret =  rawGyro - gyroOffset;

	recentGyro2 = rawGyro;

	ret = adjustRadianAngle(ret);

	recentGyro = ret;
	return ret;
}

float getRawGyroAngle(){
	return GyroAngleRadGet();
}

void resetAllIMEs(){

	return;

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	SensorValue[I2C_3] = 0;
	SensorValue[I2C_4] = 0;
/*
	motorEncoder1Offset = SensorValue[I2C_1];
	motorEncoder2Offset = SensorValue[I2C_2];
	motorEncoder3Offset = SensorValue[I2C_3];
	motorEncoder4Offset = SensorValue[I2C_4];
*/
}

float degToRad(float degrees){
	return degrees/360*2*PI;
}

int deadzoneCompensate(int in){
	if(abs(in) < deadzone_width) {in = 0; }
	return in;
}

void softResetGyro(){
	gyroOffset = getRawGyroAngle();
}

void hardResetGyro(){
	gyroOffset = gyroMountingAngle;
	GyroReinit();
}

//------------AUXILARY FUNCTIONS--------------

void alternateBlinkers(){
	ledflashconfig = !ledflashconfig;
	SensorValue[led2] = ledflashconfig;
	SensorValue[led3] = !ledflashconfig;
}

//------------ARM CODE--------------

void actuatorRotate(){


	//claw closed
	//writeDebugStreamLine("actuatorRotate: %d", actuator_rotation_state);


	if(actuator_rotation_state == 0){
		setClawClosedPos();
	} else if (actuator_rotation_state == 1){
		//arm up
		setArmUpPos();
	} else if (actuator_rotation_state == 2) {
		//claw open
		setClawOpenPos();
	} else if (actuator_rotation_state == 3) {
		//arm down
		setArmDownPos();
	}

	actuator_rotation_state = (actuator_rotation_state + 1) % 4;

}

void armUp() {
	armSetSpeed(armSpeedGoingUp);
}

void armDown(){
	armSetSpeed(-1 * armSpeedGoingDown);
}

void armStop(){
	armSetSpeed(0);
}

void armSetSpeed(int speed){
	motor[armmotor1L] = speed;
	motor[armmotor2L] = speed;
	motor[armmotor1R] = -1 * speed;
	motor[armmotor2R] = -1 * speed;
}

void setArmDownPos(){
	setArmPos(armpotlowval);
}

void setArmUpPos(){
	setArmPos(armpothighval);
}

void setArmPos(int target){
	targetArmPosition = target;
}

void automaticArm(){
		if(targetArmPosition == ARM_NO_TARGET) return;

		int decelerationStart = (armpothighval - armpotlowval) / 10; //decelerate the last 1/20 of the trip so it's smoother.
		int stopPoint = (armpothighval - armpotlowval) / 40;
		int armMinSpeed = 20;
		int armUpIdleSpeed = 10;

		int SensorVal = SensorValue[armpot];

		int delta = targetArmPosition - sensorVal;

		int speed = 0;

		if(delta < 0) speed = -1 * armSpeedGoingDown;
		else speed = armSpeedGoingUp;


		if(abs(delta) < decelerationStart){
			speed = speed * abs(delta) / (float) decelerationStart;
		}

		if(abs(delta) < stopPoint){
			speed = armUpIdleSpeed;
			if(targetArmPosition == armpotlowval) {speed = speed * -1; }
		}

		armSetSpeed(speed);
}

void toggleArm(){
		if(SensorValue[armpot] > (armpotlowval + armpothighval)/2){
			setArmDownPos();
		} else {
			setArmUpPos();
		}
}

void armControl(){

	if(vexRT[Btn6D] && !BUTTON_6D_STATE) {
		toggleArm();
		BUTTON_6D_STATE = 1;
	} else if(!vexRT[Btn6D]) {BUTTON_6D_STATE = 0;}

	/*
	if(false && !BUTTON_5U_STATE && vexRT[Btn5U]) { //DISABLE
		actuatorRotate();
		BUTTON_5U_STATE = 1;
	} else if (!vexRT[Btn5U]){
		BUTTON_5U_STATE = 0;
	}
	*/

	if(vexRT[Btn7U]) { //manual control override
		if(mostRecentArmInstruction != ARM_MOVING_UP) {
				armUp();
				targetArmPosition = ARM_NO_TARGET;
				mostRecentArmInstruction = ARM_MOVING_UP;
			}

	} else if (vexRT[Btn7D]){ //manual control override
		if(mostRecentArmInstruction != ARM_MOVING_DOWN) {
			armDown();
			targetArmPosition = ARM_NO_TARGET;
			mostRecentArmInstruction = ARM_MOVING_DOWN;
		}
	} else if (targetArmPosition != ARM_NO_TARGET) { //set up targets
		//automatic control
		mostRecentArmInstruction = ARM_AUTO;
		automaticArm();
	} else {
		if(mostRecentArmInstruction != ARM_STOP) {
			armStop();
			mostRecentArmInstruction = ARM_STOP;
		}
	}
}

//------------CLAW CODE--------------

void clawControl(){

	if(!BUTTON_6U_STATE && vexRT[Btn6U]) { toggleClaw(); BUTTON_6U_STATE = 1; }
	else if(!vexRT[Btn6U]) {BUTTON_6U_STATE = 0;}

	if(vexRT[Btn7L]) { //manual control override 7L
		if(mostRecentClawInstruction != CLAW_OPENING) {
				clawSetOpening();
				targetClawPosition = CLAW_NO_TARGET;
				mostRecentClawInstruction = CLAW_OPENING;
			}

	} else if (vexRT[Btn7R]){ //manual control override 7R
		if(mostRecentClawInstruction != CLAW_CLOSING) {
			clawSetClosing();
			targetClawPosition = CLAW_NO_TARGET;
			mostRecentClawInstruction = CLAW_CLOSING;
		}
	} else if (targetClawPosition != CLAW_NO_TARGET) { //set up targets
		//automatic control
		mostRecentClawInstruction = CLAW_AUTO;
		automaticClaw();
	} else {
		if(mostRecentClawInstruction != CLAW_STOP) {
			clawSetStop();
			mostRecentClawInstruction = CLAW_STOP;
		}
	}

	/*
	if(vexRT[Btn5U] && SensorValue[clawpot] > clawpotopenval){
		clawSetOpening();
		clawNewRecent = 1;
	} else if(vexRT[Btn5D]) {
		clawSetClosing();
		clawNewRecent = -1;
	} else {
		if(clawNewRecent == 1){
			clawSetStop();
			//clawSetOpeningSlow();
		} else if(clawNewRecent == -1) {
			clawSetClosingSlow();
		} else {
			clawSetStop();
		}
	}
	*/
}

void automaticClaw(){
		if(targetClawPosition == CLAW_NO_TARGET) return;

		int stoppingPoint = 25;

		int speed = 0;

		int sensorVal = SensorValue[clawpot];

		int delta = targetClawPosition - sensorVal;

		int fullSpeedTimeOut = 700;

		//positive numbers are closing.

		if(targetClawPosition == clawpotopenval) { //opening

			if(Time1[T1] < fullSpeedTimeOut){ //% remaining to closed. More than clawHighPowerCutoffClosing remaining.
				speed = 70; //closing
			} else {
				speed = clawIdleSpeedOpening; //no stalling value.
			}

		} else if (targetClawPosition == clawpotclosedval) { //closing

			if(Time1[T1] < fullSpeedTimeOut){ //% remaining.
				speed = -70;
			} else {
				speed = -1 * clawIdleSpeedClosing; //no stalling value.
			}

		}

		/*
		if(abs(delta) < stoppingPoint){
			speed = 0;
		}

		if((sensorVal > clawpotclosedval && targetClawPosition==clawpotclosedval) || (sensorVal < clawpotopenval && targetClawPosition==clawpotopenval)) {
			speed = 0;
		}
		*/

		writeDebugStreamLine("pot: %d, target: %d, speed: %d, delta: %d, percentage: %f", sensorVal, targetClawPosition, speed, delta, abs((sensorVal - clawpotopenval) / (float) (clawpotclosedval - clawpotopenval)));

		setClawSpeed(speed);
}

void setClawSpeed(int speed){
	motor[clawmotorL] = -1 * speed;
	motor[clawmotorR] = speed;
}

void clawSetStop(){
	setClawSpeed(0);
}

void clawSetClosing(){
	setClawSpeed(clawSpeed);
	clearTimer(T1);
}

void clawSetOpening(){
	setClawSpeed(-1 * clawSpeed);
	clearTimer(T1);
}

void clawSetClosingSlow(){
	setClawSpeed(1 * clawIdleSpeedClosing);
}

void clawSetOpeningSlow(){
	setClawSpeed(-1 * clawIdleSpeedOpening);
}

void toggleClaw(){
	if(SensorValue[clawpot] < (clawpotclosedval + clawpotopenval)/2){ //close to being open
			setClawClosedPos();
		} else {
			setClawOpenPos();
		}
}

void setClawClosedPos(){
	setClawPos(clawpotclosedval);
	clearTimer(T1);
}

void setClawOpenPos(){
	setClawPos(clawpotopenval);
	clearTimer(T1);
}

void setClawPos(int target){
	targetClawPosition = target;
}

//------------DEAD CODE--------------

/* Manual moveAbsolute
	int xdelta = fieldX - currentPositionX;
	int ydelta = fieldY - currentPositionY;

	float movementAngle = computeAngleFromDeltas(xdelta, ydelta);
	//int rdelta = fieldR - currentPositionR;

	int distance = sqrt(xdelta*xdelta + ydelta*ydelta);
	int steps = 1;


	float startRAngle = computeAngleFromR(currentPositionR);
	float endRAngle = targetfieldAngle-startRAngle;
	float currentRAngle = 0;

	float turnByAngle = endRAngle/steps;

	int delayTime = distance/speed/steps*100;
	float yawAnglePerSecond = turnByAngle/delayTime*100;

	for(int i = 0; i < steps; i++){
		//movementAngle
		alternateBlinkers();
		movePolarRelative(movementAngle-currentRAngle, speed);
		addConcurrentYawAnglePerSecond(yawAnglePerSecond);
		delay(delayTime);
		currentRAngle += turnByAngle;
	}
*/


/*
void yawRelative(float targetRotation, int speed){
	speed = abs(speed);
	if(targetRotation < 0) speed = speed * -1;

	yawSet(speed);
	int rotationSoFar = currentPositionR;

	while(true){ //TODO
		trackPosition();
		delay(5);
		imeGet(0, &rotationSoFar);
	}
	stopAll();
}
*/

/*
void clawControl(){

	if(vexRT[Btn7L] && clawState != CLAW_OPENING) {
		openClaw();
	} else if(vexRT[Btn7R] && clawState != CLAW_CLOSING){
		closeClaw();
	} else {
		stopClaw();
	}
}
*/

/*
		if(targetClawPosition == clawpotclosedval) { //closing

			if(abs((sensorVal - clawpotclosedval) / (float) (clawpotclosedval - clawpotopenval)) > (clawHighPowerCutoffClosing)){ //% remaining to closed. More than clawHighPowerCutoffClosing remaining.
				speed = 127; //closing
			} else {
				speed = 25; //no stalling value.
			}


		} else if (targetClawPosition == clawpotopenval) { //opening

			if(abs((sensorVal - clawpotopenval) / (float) (clawpotclosedval - clawpotopenval)) > (clawHighPowerCutoffOpening)){ //% remaining.
				speed = -127;
			} else {
				speed = -25; //no stalling value.
			}

		}
*/

//------------END--------------
