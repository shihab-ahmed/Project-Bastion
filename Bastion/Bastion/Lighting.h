#pragma once
class Lighting
{
public:
	Lighting();
	void LightEnable();
	void LightDisbale();
	void LightReset();
	void SetDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha);
	void SetAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha);
	void SetSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha);
	void SetEmmision(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha);
	void SetShininess(GLfloat rate);
	void SetPosition(GLfloat x, GLfloat y, GLfloat z, GLint lightNo);
	void SetMetalWhite();
	void SetMetaBlack();
	void SetMetalSilver();
	void SetMetalGold();
	void SetBlueEnergy();
	void SetBlueShield();
	void SetRedShield();
	~Lighting();
private:
	int Beltangle;
	float speed;
};

