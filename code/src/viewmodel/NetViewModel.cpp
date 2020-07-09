#include "NetViewModel.h"

NetViewModel::NetViewModel(): m_NetM(nullptr) {}

Command NetViewModel::get_add_neuron_command() {
    return [this](std::any&& x)->bool {
        Neuron&& y = std::any_cast<Neuron>(x);
        return this->m_NetM->get_add_neuron_command()(std::move(y));
    };
}

Notification  NetViewModel::get_Notification() 
	{
		return [this](uint32_t uID)
		{
			if (uID == DRAW_NOTIF) {
				this->Fire(uID);
			}
		};
	}

//EXPOSE ATTRIBUTES
std::shared_ptr<Graph> NetViewModel::get_FNN()
{
    return (this->m_NetM->get_FNN());
}

//ATTACH  MODEL
void NetViewModel::attach_Model(std::shared_ptr<NetModel> refModel) noexcept
{
    this->m_NetM = refModel;
}
std::shared_ptr<NetModel> NetViewModel::detach_Model() noexcept
{
    std::shared_ptr<NetModel> tmp_ptr = this->m_NetM;
    this->m_NetM = nullptr;
    return tmp_ptr;
}
