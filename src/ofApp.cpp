#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(20);
	cam.setNearClip(0.0f);
	cam.setFarClip(-1.0f);
	cam.setGlobalPosition({ 0,0,1500});
	const double r = 1;
	system = ParticleSystem(3000);

	std::shared_ptr<ParticleUpdater_Collision> updater_Col(new ParticleUpdater_Collision(750.0));
	std::shared_ptr<ParticleUpdater_Gravity> updater_G(new ParticleUpdater_Gravity());

	std::shared_ptr<ParticleEmitter> emitter(new ParticleEmitter(500));
	emitter->set_radius(150);
	std::shared_ptr<ParticleGenerator_Flag> gen_flag(new ParticleGenerator_Flag());
	std::shared_ptr<ParticleGenerator_Color> gen_col(new ParticleGenerator_Color());
	std::shared_ptr<ParticleGenerator_Vel> gen_vel(new ParticleGenerator_Vel());
	std::shared_ptr<ParticleGenerator_Acc> gen_acc(new ParticleGenerator_Acc());
	std::shared_ptr<ParticleGenerator_Positions> gen_pos(new ParticleGenerator_Positions());
	std::shared_ptr<ParticleGenerator_Time> gen_time(new ParticleGenerator_Time());
	
	emitter->addGenerator(gen_flag);
	emitter->addGenerator(gen_col);
	emitter->addGenerator(gen_pos);
	emitter->addGenerator(gen_vel);
	emitter->addGenerator(gen_acc);
	emitter->addGenerator(gen_time);
	system.addEmitter(emitter);
	system.addUpdater(updater_G);
	system.addUpdater(updater_Col);

	std::shared_ptr<ParticleUpdater_Time> updater_T(new ParticleUpdater_Time());
	system.setTimeUpdater(updater_T);

	render.generate(&system,r);
	Gravity = updater_G;
	Collsiion = updater_Col;
	gui.setup();

	gui.add(G_X.setup("Sila X", 0, -20, 20));
	gui.add(G_Y.setup("Sila Y", -9.81, -20, 20));
	gui.add(G_Z.setup("Sila Z", 0, -20, 20));
	gui.add(dt.setup("Krok czasowy", 0.1, 0.0001, 0.9));
	gui.add(R.setup("Promieñ sfery", 650, 10, 2000));
	gui.add(addButton.setup("add emmiter", false));
}

//--------------------------------------------------------------
void ofApp::update(){
	Gravity->set_acceleration(G_X, 0);
	Gravity->set_acceleration(G_Y, 1);
	Gravity->set_acceleration(G_Z, 2);
	Collsiion->set_r(R);
	system.update(dt);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	ofFill();
	cam.begin();
	//std::cout << "drawin" << std::endl;
	render.render();
	render.render_dead();
	cam.end();
	ofDisableDepthTest();
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(button == 0)
	{
		if (addButton)
		{
			double xz = x- 1920/2.0;
			double yz  = -(y - 1080/2.0);
			double zz = 0.0;

			std::vector<double> pos = { xz,yz,0 };
			std::shared_ptr<ParticleEmitter> emitter(new ParticleEmitter(1, pos,0.000001,1.0));
			std::shared_ptr<ParticleGenerator_Flag> gen_flag(new ParticleGenerator_Flag());
			std::shared_ptr<ParticleGenerator_Vel> gen_vel(new ParticleGenerator_Vel());
			std::shared_ptr<ParticleGenerator_Acc> gen_acc(new ParticleGenerator_Acc());
			std::shared_ptr<ParticleGenerator_Color> gen_col(new ParticleGenerator_Color());
			std::shared_ptr<ParticleGenerator_Positions> gen_pos(new ParticleGenerator_Positions());
			std::shared_ptr<ParticleGenerator_Time> gen_time(new ParticleGenerator_Time());

			emitter->addGenerator(gen_flag);
			emitter->addGenerator(gen_pos);
			emitter->addGenerator(gen_col);
			emitter->addGenerator(gen_vel);
			emitter->addGenerator(gen_acc);
			emitter->addGenerator(gen_time);
			system.addEmitter(emitter);
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
