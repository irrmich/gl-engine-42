//
// Renderer.hpp for  in /home/jochau_g//dev/opengl/glEngine
// 
// Made by gael jochaud-du-plessix
// Login   <jochau_g@epitech.net>
// 
// Started on  Tue Feb 14 17:12:21 2012 gael jochaud-du-plessix
// Last update Thu Jun 21 00:53:16 2012 loick michard
//

#ifndef _GLE_RENDERER_HPP_
# define _GLE_RENDERER_HPP_

# include <string>
# include <Scene.hpp>
# include <Mesh.hpp>
# include <Camera.hpp>
# include <FrameBuffer.hpp>
# include <Rect.hpp>

namespace gle {

  //! Rendering class
  /*!
    Controls all rendering operations.
    To use it, first set up an OpenGL context and set is as active.
    Then, just create a new Renderer object, set it up and call
    the function "render" to get started.
  */

  class Renderer {
  public:
    
    //! Construct a new renderer
    Renderer();

    //! Destruct a renderer
    ~Renderer();

    //! Clear the context
    void clear();

    //! Render a scene
    void render(Scene* scene, const Rectf& size, FrameBuffer* customFramebuffer=NULL);

  private:
    void _buildIndexesBuffer(const std::list<gle::Mesh*> & meshes);
    void _renderEnvMap(gle::Scene* scene);
    void _renderMesh(gle::Scene* scene, gle::Mesh* mesh);
    void _renderMeshes(gle::Scene* scene, gle::Mesh* mesh);
    void _setCurrentProgram(gle::Scene* scene,
			    gle::Camera* camera);
    void _setMaterialUniforms(gle::Material* material);
    void _setSceneUniforms(gle::Scene* scene, gle::Camera* camera);
    void _setMeshUniforms(gle::Scene* scene, gle::Mesh* mesh);

    gle::Program*	_currentProgram;
    gle::Bufferui	_indexesBuffer;
  };

};

#endif /* _GLE_RENDERER_HPP_ */
