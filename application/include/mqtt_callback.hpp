#ifndef MQTT_CALLBACK_H
#define MQTT_CALLBACK_H

#include <iostream>
#include <cstring>

#include <mqtt/async_client.h>

class callback : public virtual mqtt::callback 
{
    virtual void connection_lost(const std::string& cause) override
    {
	    std::cout << "connection_lost!" << std::endl;
    }
    virtual void delivery_complete(mqtt::delivery_token_ptr tok) override
    {
	    std::cout << "delivery_complete!" << std::endl;
    }
    virtual void message_arrived(mqtt::const_message_ptr msg) override
    {
	    std::cout << "message_arrived!" << std::endl;
	    this->new_msg_arrived = true;
	    this->msg = msg->to_string();
    }
 
 public :
	bool IsMsgArrived()
	{
		return this->new_msg_arrived;
	}
	
	std::string GetSubTopicMsg()
	{
		return this->msg;
	}
	
 private:
 	std::string msg;
 	bool new_msg_arrived; 
};


class my_iaction_listener : public virtual mqtt::iaction_listener
{
    void on_failure(const mqtt::token& tok) override
    {
    	std::cout << "Mqtt Filed" << std::endl;
    }
    
    void on_success(const mqtt::token& tok) override
    {
    	std::cout << "Mqtt Success" << std::endl;
    }    
};

#endif