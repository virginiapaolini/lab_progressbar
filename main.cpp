#include <iostream>
#include "FileLoader.h"
#include "ProgressBar.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    SourceFile* source1 = new SourceFile("directories");
    SourceFile* source2 = new SourceFile("sound files");

    source1->addResource({"texture.png", "colour.rgb", "", "model.obj", "script.txt"});
    source2->addResource({"audio.mp3", "sound.wav", "title.txt"});

    FileLoader* loaderApp = new FileLoader;
    ProgressBar* bar = new ProgressBar(loaderApp);

    loaderApp->addFilesToLoad(source1);
    loaderApp->addFilesToLoad(source2);

    loaderApp->loadAll();

    return 0;
}