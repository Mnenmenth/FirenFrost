#include "../render/Render.h"

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

int main(int argc, char** argv) {

    Render render("Test", 800, 600);

    render.renderLoop();

    return 0;
}