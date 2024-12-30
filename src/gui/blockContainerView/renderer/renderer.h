#ifndef renderer_h
#define renderer_h

typedef unsigned int ElementID;

#include "middleEnd/blockContainerWrapper.h"
#include "../viewManager/viewManager.h"
#include "backend/evaluator/evaluator.h"

// This is the renderer interface. It defines all the methods that non-windowing
// or renderer-specific code should be able to call. Each implementation is
// responsible for defining a render function and calling it in a loop.

// Under Construction Notes -----
// placeholder system for submitting sprites using BlockType, not sure how they
// will be handled

// Element Types ------------------------------
struct SelectionElement {
    SelectionElement() = default;
    SelectionElement(Position topLeft, Position bottomRight, bool inverted = false)
        : topLeft(topLeft), bottomRight(bottomRight), inverted(inverted) {}

    SelectionElement(Position topLeft, bool inverted = false)
        : topLeft(topLeft), bottomRight(topLeft), inverted(inverted) {}
    
    Position topLeft;
    Position bottomRight;
    bool inverted;
};

struct BlockPreview {
    BlockPreview() = default;
    BlockPreview(BlockType type, Position position, Rotation rotation)
        : type(type), position(position), rotation(rotation) {}
    
    BlockType type;
    Position position;
    Rotation rotation;
};

struct ConnectionPreview {
    ConnectionPreview() = default;
    ConnectionPreview(Position input, Position output)
        : input(input), output(output) {}
    
    Position input;
    Position output;
};

struct HalfConnectionPreview {
    HalfConnectionPreview() = default;
    HalfConnectionPreview(Position input, FPosition output)
        : input(input), output(output) {}
    
    Position input;
    FPosition output;
};

// Renderer -----------------------------------

class Renderer {
    friend class ElementCreator;
public:
    // main flow
    virtual void setBlockContainer(BlockContainerWrapper* blockContainer) = 0;
    virtual void setEvaluator(Evaluator* evaluator) = 0;

    virtual void updateView(ViewManager* viewManager) = 0;
    virtual void updateBlockContainer(DifferenceSharedPtr diff) = 0;

    virtual float getLastFrameTimeMs() const = 0;

private:
    // elements
    virtual ElementID addSelectionElement(const SelectionElement& selection) = 0;
    virtual void removeSelectionElement(ElementID selection) = 0;
    
    virtual ElementID addBlockPreview(const BlockPreview& blockPreview) = 0;
    virtual void removeBlockPreview(ElementID blockPreview) = 0;
    
    virtual ElementID addConnectionPreview(const ConnectionPreview& connectionPreview) = 0;
    virtual void removeConnectionPreview(ElementID connectionPreview) = 0;

    virtual ElementID addHalfConnectionPreview(const HalfConnectionPreview& halfConnectionPreview) = 0;
    virtual void removeHalfConnectionPreview(ElementID halfConnectionPreview) = 0;
    
    virtual void spawnConfetti(FPosition start) = 0;
};

#endif /* renderer_h */
