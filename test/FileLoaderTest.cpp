//
// Created by Virginia Paolini on 23/04/25.
//
#include <gtest/gtest.h>
#include "../FileLoader.h"
#include "../Observer.h"
#include "../SourceFile.h"

class TestObserver : public Observer {
public:
    vector<int> updates;
    void update(int progress) override {
        updates.push_back(progress);
    }
    ~TestObserver() override = default;
    void attach() override {}
    void detach() override {}
};


class FileLoaderTestFixture : public ::testing::Test {
protected:
    FileLoader loader;
    TestObserver* observer = new TestObserver;
    SourceFile* file1 = new SourceFile("File 1");
    SourceFile* file2 = new SourceFile("File 2");

    void SetUp() override {
        loader.subscribe(observer);
        file1->addResource({"res1", "res2", "res3"});
        file2->addResource({"a", "b"});
    }

    void TearDown() override {
        delete file1;
        delete file2;
    }
};


TEST_F(FileLoaderTestFixture, NotifyCallsObserver) {
    loader.notify(55);
    ASSERT_EQ(observer->updates.size(), 1);
    EXPECT_EQ(observer->updates[0], 55);
}

TEST_F(FileLoaderTestFixture, UnsubscribeRemovesObserver) {
    loader.unsubscribe(observer);
    loader.notify(77);
    EXPECT_TRUE(observer->updates.empty());
}

TEST_F(FileLoaderTestFixture, AddAndRemoveFilesToLoad) {
    EXPECT_EQ(loader.getSize(), 0);
    loader.addFilesToLoad(file1);
    EXPECT_EQ(loader.getSize(), 1);
    loader.removeFilesToLoad(file1);
    EXPECT_EQ(loader.getSize(), 0);
}

