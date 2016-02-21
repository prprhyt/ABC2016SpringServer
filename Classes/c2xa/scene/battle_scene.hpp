﻿
/**

    @file   battle_scene.hpp
    @brief  battle_scene

    @author 新ゝ月かりな(NewNotMoon)
    @date   created on 2016/02/09

*/
#pragma once
#ifndef C2XA_SCENE_BATTLE_SCENE_HPP
#define C2XA_SCENE_BATTLE_SCENE_HPP

#include <array>

#include <cocos2d.h>

#include <c2xa/utility.hpp>
#include <c2xa/communication/data.hpp>
#include <c2xa/math/sample.hpp>
#include <c2xa/math/fast_fourier_transform.hpp>

namespace c2xa
{
    class communication_node;

    namespace scene
    {
        class battle_scene
            : public cocos2d::Scene
        {
        public:
            using sample = math::sample<data, 16, 16>;
            using fft_buffer_type = std::array<double, battle_scene::sample::sampling_number * 2>;

        private:
            fft fft_;
            sample sample_1p;
            sample sample_2p;
            fft_buffer_type tmp_;

        public:
            battle_scene();
            static battle_scene* create( communication_node* c )
            {
                return create_template<battle_scene>( c );
            }
            virtual bool init( communication_node* );
            virtual void update( float ) override;
        };
    }
}

#endif//C2XA_SCENE_BATTLE_SCENE_HPP