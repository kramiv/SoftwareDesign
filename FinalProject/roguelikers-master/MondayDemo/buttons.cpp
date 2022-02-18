#include"../react.h"

int main() {
  //init();  // commented out for now

  //add_yaml("button.yaml", {{"id", 0}});
//goal: move it around
//in client-server setup: client = web browser (has running program) and server = C++ file we write
/*
brower continuously runs. Not the server. we don't use server unless user sends something there.
(saves human money)
so: start the server from the beginning whenever the user does something. start from 0 again.
so, I will use a _global_mem file that the .cpp can reference and edit each time it runs
so that the .cpp file can reference it and not start from 0.
each separate 'snapshot' of the webpage is a new run on the server.
*/
  add_yaml("buttonlab8.yaml", {{"left", 100}, {"top", 100}});//I can use a percent. Put inside of
  //string or quotes. It is relative to teh containing element (the webpage browser)
  add_yaml("buttonlab8.yaml", {{"left", 100}, {"top", 100}});
  //add_yaml("button.yaml", {{"id", 1}});
  //add_yaml("button.yaml", {{"id", 2}});
  //how to remove yaml?
//idea is to move yamls around. Would I just be copying them a bunch of times?
  quit();
}



//also: mouse: how to get cursor functionality. Is there a way to get the coordinates or etc
//of the mouse?
//nothing built in.
//we have to calculate it each time using information from global mem
//shape of cursor: ?? if the user presses an arrow key, that will give intsructions.
//Prof Olaf will create an example by roughly class time tomorrow to look at keyboard functionality




//note to send with git pull/push:
/*
Please read for Monday functional demo: the physical movement of the Hero view on the wepbage screen is described here. In addition, Prof. Olaf says he will give an example of how to use keybindings by roughly classtime on Friday. We will need to use _global_mem to update the positions of the Hero. Please read for full explanation and look at the code."
*/