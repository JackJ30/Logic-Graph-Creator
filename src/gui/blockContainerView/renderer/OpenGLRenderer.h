#ifndef OpenGLRenderer_h
#define OpenGLRenderer_h

#include <QOpenGLFunctions_4_3_Core>
#include <QMatrix4x4>

#include "renderer.h"

class OpenGLRenderer : public Renderer, QOpenGLFunctions_4_3_Core {
 public:
    OpenGLRenderer() = default;

    void initialize();
    void resize(int w, int h);
    void render();

    void setBlockContainer(BlockContainerWrapper* blockContainer) override;
    void setEvaluator(Evaluator* evaluator) override;

    void updateView(ViewManager* viewManager) override;

    inline float getLastFrameTimeMs() const override { return lastFrameTime; }

 private:
    // element functions
    ElementID addSelectionElement(const SelectionElement& selection) override;
    void removeSelectionElement(ElementID selection) override;
    
    ElementID addBlockPreview(const BlockPreview& blockPreview) override;
    void removeBlockPreview(ElementID blockPreview) override;
    
    ElementID addConnectionPreview(const ConnectionPreview& connectionPreview) override;
    void removeConnectionPreview(ElementID connectionPreview) override;

    ElementID addHalfConnectionPreview(const HalfConnectionPreview& halfConnectionPreview) override;
    void removeHalfConnectionPreview(ElementID halfConnectionPreview) override;
    
    void spawnConfetti(FPosition start) override;

 private:
    QMatrix4x4 viewProjection;
    
    float lastFrameTime = 0.0f;
};

#endif
