//
// Created by Virginia Paolini on 23/04/25.
//
#include <gtest/gtest.h>
#include "../FileLoader.h"

class FileLoaderTest : public ::testing::Test {
protected:
    void setUp()  {
        // tipo costruttore
        SourceFile* source1 = new SourceFile({"text.txt", "audio.mp3"});
        FileLoaderTest* loader1 = new FileLoaderTest(source1);
    }

    void tearDown() {
        // tipo distruttore
        delete loader;
        delete source;
    }

    SourceFile* source;
    FileLoader* loader;
};
