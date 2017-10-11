#include <iostream>
#include "engine.h"
#include "input_handler.h"
#include "entity_manager.h"
#include "physics_system.h"
#include "renderer.h"

using namespace std;


void enter_state_1(engine &eng)
{
	std::cout << "Entering state 1" << std::endl;
}

void do_state_1(engine &eng)
{
	std::cout << "Doing state 1" << std::endl;
}

void exit_state_1(engine &eng)
{
	std::cout << "Exiting state 1" << std::endl;
}

void enter_state_2(engine &eng)
{
	std::cout << "Entering state 2" << std::endl;
}

void do_state_2(engine &eng)
{
	std::cout << "Doing state 2" << std::endl;
}

void exit_state_2(engine &eng)
{
	std::cout << "Exiting state 2" << std::endl;
}

void enter_state_3(engine &eng)
{
	std::cout << "Entering state 3" << std::endl;
}

void do_state_3(engine &eng)
{
	std::cout << "Doing state 3" << std::endl;
}

void exit_state_3(engine &eng)
{
	std::cout << "Exiting state 3" << std::endl;
}

void enter_state_4(engine &eng)
{
	std::cout << "Entering state 4" << std::endl;
}

void do_state_4(engine &eng)
{
	std::cout << "Doing state 4" << std::endl;
}

void exit_state_4(engine &eng)
{
	std::cout << "Exiting state 4" << std::endl;
}

int main(int arg, char **argv)
{
    auto eng = engine::get();

    eng.add_state("1", enter_state_1, do_state_1, exit_state_1);
    eng.add_state("2", enter_state_2, do_state_2, exit_state_2);
    eng.add_state("3", enter_state_3, do_state_3, exit_state_3);
    eng.add_state("4", enter_state_4, do_state_4, exit_state_4);

    // Input handler does not render
    eng.add_subsystem(input_handler::get(), true, false);
    // Entity manager has to update and render
    eng.add_subsystem(entity_manager::get(), true, true);
    // Physics system does not render
    eng.add_subsystem(physics_system::get(), true, false);
    // Renderer does not update.
    eng.add_subsystem(renderer::get(), false, true);

    auto e = entity_manager::get().create("ENTITY", "Test");
	
	//R//Appears at the top of the console when the program is first run 
	std::cout << "e.get_trans: " << e.get_trans().x << " " << e.get_trans().y << " " << e.get_trans().z << std::endl << std::endl;
    
	e.add_component<physics_component>(physics_system::get().create("RIGID", e));
    e.add_component<render_component>(renderer::get().create("RENDER", e, string("Blue"), "Box", "Physical"));
	
	//e.update(delta_time);


	//R//Messing around with how to create a player entity
	auto Player1 = entity_manager::get().create("ENTITY", "playerplayer");
	//Player1.set_trans(21.0f, 5.0f, 16.0f);
	cout << "Player 1 exists and is located at X/Y/Z:" << endl;
	//cout << Player1.get_trans().x << "/" << Player1.get_trans().y << "/" << Player1.get_trans().z << endl << endl;
	Player1.add_component<physics_component>(physics_system::get().create("RIGID", Player1));
	Player1.add_component<render_component>(renderer::get().create("RENDER", Player1, string("Blue"), "Box", "Physical"));


    eng.run();




	
    
    return 0;
}