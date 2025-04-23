#include <iostream>
#include "FileLoader.h"
#include "ProgressBar.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    SourceFile* source1 = new SourceFile("directories");
    SourceFile* source2 = new SourceFile("sound files");

    source1.addResource({"texture.png", "colour.rgb", "", "model.obj", "script.txt"});
    source2.addResource({"audio.mp3", "sound.wav", "title.txt"});

    FileLoader* loaderApp = new FileLoader(&source1);
    ProgressBar* bar = new ProgressBar(loaderApp);

    loaderApp->loadResources();

    FileLoader* loaderApp2 = new FileLoader(&source2);
    ProgressBar* bar2 = new ProgressBar(loaderApp2);
    loaderApp2->loadResources();

    return 0;
}