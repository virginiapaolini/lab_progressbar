//
// Created by Virginia Paolini on 23/04/25.
//
#include <gtest/gtest.h>
#include "../SourceFile.h"

TEST(SourceFileTest, ConstructorTest) {
SourceFile sourceFile("source1");
EXPECT_EQ(sourceFile.getSourceName(), "source1");
EXPECT_TRUE(sourceFile.getSourceName().empty());
}

TEST(SourceFileTest, AddResourceTest) {
SourceFile sourceFile1("mySource");
sourceFile1.addResource({"text.txt", "audio.mp4"});
EXPECT_EQ(sourceFile1.getResources().size(), 2);
list<string> filesContained = {"text.txt","audio.mp4"};
EXPECT_EQ(sourceFile1.getResources(), filesContained);
}

TEST(SourceFileTest, RemoveResourceTest) {
SourceFile sourceFile1("mySource");
sourceFile1.addResource({"text.txt", "audio.mp4"});
sourceFile1.removeResource({"audio.mp4"});
EXPECT_EQ(sourceFile1.getResources().size(), 1);

list<string> filesContained2 = {"text.txt"};
EXPECT_EQ(sourceFile1.getResources(), filesContained2);
sourceFile1.removeResource({"text.txt"});
EXPECT_TRUE(sourceFile1.getResources().empty());
}


