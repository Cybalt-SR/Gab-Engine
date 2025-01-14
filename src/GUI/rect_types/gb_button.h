#pragma once

#include "../gb_rect.h"
#include "../interfaces/gb_onEnter.h"
#include "../interfaces/gb_onExit.h"
#include "../interfaces/gb_onClick.h"
#include <functional>
namespace gbe {
	namespace gui {
		class gb_button : public gb_rect, public gb_onEnter, public gb_onExit, public gb_onClick{
		private:
			bool hovered;
			glm::vec4 current_color;
			std::function<void()> onClickAction;
		public:
			glm::vec4 normal_color;
			glm::vec4 hovered_color;
			glm::vec4 pressed_color;
			float transition_speed = 10;

			void Render() override;
			void Update(float delta) override;

			void onEnter() override;
			void onExit() override;
			void onClick() override;

			void Set_onClickAction(std::function<void()> new_action);
		};
	}
}