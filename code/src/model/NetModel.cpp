#include "NetModel.h"

NetModel::NetModel(){
    this->FNN=make_shared<Graph>();
}

std::function<bool(Neuron&&)> NetModel::get_add_neuron_command() {
    return [this](Neuron&& x)->bool {
        return this->add_neuron(std::move(x));
    };
}

std::shared_ptr<Graph> NetModel::get_FNN()
{
    return std::shared_ptr<Graph>(this->FNN);
}

void NetModel::set_update_display_data_notification(Notification&& notification)
{
    AddNotification(std::move(notification));
}


bool NetModel::add_neuron(Neuron&& x)
{
    return this->FNN->add_neuron(std::move(x));
}

std::function<bool(int,int)>  NetModel::get_connect_command(){
    return [this](int a,int b)->bool{
        return add_link(a,b);
    };
}

bool NetModel::add_link(int src,int dst){
    if(src==dst) return false;
    int i;
    for(i=0;i<this->FNN->_weights.size();i++){
        if(src==this->FNN->_weights[i]._from&&dst==this->FNN->_weights[i]._to) return false;
    }
    Weight w;
    w._from=src;
    w._to=dst;
    return this->FNN->add_link(std::move(w));
}
