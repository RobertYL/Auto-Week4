#include "DriveTrain.h"
#include "../RobotMap.h"
#include "iostream"
using namespace std;

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(LEFTMOTOR)), right(new TalonSRX(RIGHTMOTOR)),
							gyro(new ADXRS450_Gyro()) {


	left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	// left->ConfigEncoderCodesPerRev(360);
	left->SetSelectedSensorPosition(0,0,10);
	right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	// right->ConfigEncoderCodesPerRev(360);
	right->SetSelectedSensorPosition(0,0,10);

	std::cout<<"DriveTrain Constructor Successful" <<std::endl;
	right->SetInverted(true);

	//gyro->Reset();
	//gyro->Calibrate();



}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	std::cout<<"DriveTrain InitDefaultCommand Successful" <<std::endl;
	//SetDefaultCommand(new TankDrive());
}


double DriveTrain::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

void DriveTrain::tankDrive(double leftVal, double rightVal) {
	left->Set(ControlMode::PercentOutput, DriveTrain::Limit(-leftVal, 0.5));
	right->Set(ControlMode::PercentOutput, DriveTrain::Limit(-rightVal, 0.5));
}

double DriveTrain::getAngle() {
	double angle = gyro->GetAngle();
	//-180 to 180
	while (angle > 180) {
		angle -= 360;
	}
	while (angle < -180) {
		angle += 360;
	}
	return angle;
}

void DriveTrain::gyroReset() {
	gyro->Calibrate();
}
