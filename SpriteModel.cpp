// Most of this is theoretical and based of docs, needs to be refactor to fit our use
#include "Model.h"

Model::Model(QObject *parent) : QObject(parent) {
    // Initialize the current color, current tool, etc.
    currColor = QColor(Qt::black); // Default color (we can change this)
    currTool = nullptr; // No tool selected initially
    // Initialize other members...
}

void Model::start() {
    // Reset the private values to their default states
    // You need to implement this based on your specific requirements
}

void Model::changeTool(Tool tool) {
    currTool = tool;
    emit chooseTool(tool);
}

void Model::useTool(Tool currentTool) {
    // Execute the selected tool's functionality
    if (currTool != nullptr) {
        // Call the tool's onMousePress or other methods
        currTool->onMousePress();
    }
}

void Model::undo() {
    if (!Frames.isEmpty()) {
        // Save the current frame to redo stack
        redoStack.push(currentFrame);

        // Pop the last frame from the undo stack
        Frame* lastFrame = undoStack.pop();

        // Set the current frame to the last frame
        currentFrame = lastFrame;

        // Update the view
        emit updateFrame();
    }
}

void Model::redo() {
    if (!redoStack.isEmpty()) {
        // Save the current frame to undo stack
        undoStack.push(currentFrame);

        // Pop the last frame from the redo stack
        Frame* nextFrame = redoStack.pop();

        // Set the current frame to the next frame
        currentFrame = nextFrame;

        // Update the view
        emit updateFrame();
    }
}

void Model::previousFrame() {
    if (Frames.isEmpty()) {
        return; // No frames to display
    }

    // Find the index of the current frame
    int currentIndex = Frames.indexOf(currentFrame);

    if (currentIndex > 0) {
        // There is a previous frame
        currentFrame = Frames.at(currentIndex - 1);
        emit updateFrame();
    }
}

void Model::nextFrame() {
    if (Frames.isEmpty()) {
        return; // No frames to display
    }

    // Find the index of the current frame
    int currentIndex = Frames.indexOf(currentFrame);

    if (currentIndex < Frames.size() - 1) {
        // There is a next frame
        currentFrame = Frames.at(currentIndex + 1);
        emit updateFrame();
    }
}


void Model::changeColor() {
    // Change the current color based on RGB sliders in the view
    // Update the currColor member
    // Emit chooseColor signal to update the view
    emit chooseColor(currColor);
}
