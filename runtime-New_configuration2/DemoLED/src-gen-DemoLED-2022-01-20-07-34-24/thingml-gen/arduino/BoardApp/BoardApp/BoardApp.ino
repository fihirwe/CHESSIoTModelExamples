#include <stdint.h>
#include <Arduino.h>
/*****************************************************************************
 * Headers for type : LED
 *****************************************************************************/

// Definition of the instance struct:
struct LED_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inLED;
// Variables for the current instance state
int LED_LED_SM_State;
// Variables for the properties of the instance
uint8_t LED_PIN11_var;

};
// Declaration of prototypes outgoing messages :
void LED_LED_SM_OnEntry(int state, struct LED_Instance *_instance);
void LED_handle_inLED_LedOFF(struct LED_Instance *_instance);
void LED_handle_inLED_LedON(struct LED_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LED_LED_SM_STATE 0
#define LED_LED_SM_READY_STATE 1


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();
/*****************************************************************************
 * Headers for type : Board
 *****************************************************************************/

// Definition of the instance struct:
struct Board_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_toLED;
uint16_t id_toFAN;
uint16_t id_fromButton;
uint16_t id_port_Timer;
// Variables for the current instance state
int Board_Board_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages :
void Board_Board_OnEntry(int state, struct Board_Instance *_instance);
void Board_handle_fromButton_press(struct Board_Instance *_instance);
void Board_handle_fromButton_release(struct Board_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_port_Timer_timer_start_listener(void (*_listener)(struct Board_Instance *, uint8_t, uint32_t));
void register_external_Board_send_port_Timer_timer_start_listener(void (*_listener)(struct Board_Instance *, uint8_t, uint32_t));

// Definition of the states:
#define BOARD_BOARD_STATE 0
#define BOARD_BOARD_WAITING_STATE 1
#define BOARD_BOARD_FANONLEDOFF_STATE 2
#define BOARD_BOARD_FANOFFLEDON_STATE 3


/*****************************************************************************
 * Headers for type : FAN
 *****************************************************************************/

// Definition of the instance struct:
struct FAN_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inFAN;
// Variables for the current instance state
int FAN_FAN_State;
// Variables for the properties of the instance
uint8_t FAN_PIN12_var;

};
// Declaration of prototypes outgoing messages :
void FAN_FAN_OnEntry(int state, struct FAN_Instance *_instance);
void FAN_handle_inFAN_FanOFF(struct FAN_Instance *_instance);
void FAN_handle_inFAN_FanON(struct FAN_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define FAN_FAN_STATE 0
#define FAN_FAN_STANDBY_STATE 1


/*****************************************************************************
 * Headers for type : BUTTON
 *****************************************************************************/

// Definition of the instance struct:
struct BUTTON_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_clock_tic;
uint16_t id_toBoard;
// Variables for the current instance state
int BUTTON_Button_State;
// Variables for the properties of the instance
uint8_t BUTTON_PIN_var;

};
// Declaration of prototypes outgoing messages :
void BUTTON_Button_OnEntry(int state, struct BUTTON_Instance *_instance);
void BUTTON_handle_clock_tic_ms25_tic(struct BUTTON_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_BUTTON_send_toBoard_press_listener(void (*_listener)(struct BUTTON_Instance *));
void register_external_BUTTON_send_toBoard_press_listener(void (*_listener)(struct BUTTON_Instance *));
void register_BUTTON_send_toBoard_release_listener(void (*_listener)(struct BUTTON_Instance *));
void register_external_BUTTON_send_toBoard_release_listener(void (*_listener)(struct BUTTON_Instance *));

// Definition of the states:
#define BUTTON_BUTTON_RELEASED_STATE 0
#define BUTTON_BUTTON_STATE 1
#define BUTTON_BUTTON_PRESSED_STATE 2



struct timer2_instance_type {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
};
extern struct timer2_instance_type timer2_instance;

void timer2_setup();
void timer2_read();

//void forward_timer2_SoftButton_send_Timer_timer_start(struct SoftButton_Instance *_instance, uint8_t id, uint32_t time);
//void forward_timer2_SoftButton_send_Timer_timer_cancel(struct SoftButton_Instance *_instance, uint8_t id);
void forward_timer2_Board_send_port_Timer_timer_start(struct Board_Instance *_instance, uint8_t id, uint32_t time);
// Definition of Enumeration  DigitalState
#define DIGITALSTATE_LOW 0
#define DIGITALSTATE_HIGH 1


/*****************************************************************************
 * Implementation for type : Board
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Board_Board_OnExit(int state, struct Board_Instance *_instance);
//Prototypes: Message Sending
void Board_send_toLED_LedON(struct Board_Instance *_instance);
void Board_send_toLED_LedOFF(struct Board_Instance *_instance);
void Board_send_toFAN_FanON(struct Board_Instance *_instance);
void Board_send_toFAN_FanOFF(struct Board_Instance *_instance);
void Board_send_port_Timer_timer_start(struct Board_Instance *_instance, uint8_t id, uint32_t time);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Board_Board_OnEntry(int state, struct Board_Instance *_instance) {
switch(state) {
case BOARD_BOARD_STATE:{
_instance->Board_Board_State = BOARD_BOARD_WAITING_STATE;
Board_Board_OnEntry(_instance->Board_Board_State, _instance);
break;
}
case BOARD_BOARD_WAITING_STATE:{
Board_send_toLED_LedON(_instance);
Board_send_toFAN_FanOFF(_instance);
break;
}
case BOARD_BOARD_FANONLEDOFF_STATE:{
Board_send_toFAN_FanON(_instance);
Board_send_toLED_LedOFF(_instance);
Board_send_port_Timer_timer_start(_instance, 0, 1000);
break;
}
case BOARD_BOARD_FANOFFLEDON_STATE:{
Board_send_toFAN_FanOFF(_instance);
Board_send_toLED_LedON(_instance);
Board_send_port_Timer_timer_start(_instance, 1, 1000);
break;
}
default: break;
}
}

// On Exit Actions:
void Board_Board_OnExit(int state, struct Board_Instance *_instance) {
switch(state) {
case BOARD_BOARD_STATE:{
Board_Board_OnExit(_instance->Board_Board_State, _instance);
break;}
case BOARD_BOARD_WAITING_STATE:{
break;}
case BOARD_BOARD_FANONLEDOFF_STATE:{
break;}
case BOARD_BOARD_FANOFFLEDON_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Board_handle_fromButton_press(struct Board_Instance *_instance) {
if(!(_instance->active)) return;
//Region Board
uint8_t Board_Board_State_event_consumed = 0;
if (_instance->Board_Board_State == BOARD_BOARD_FANOFFLEDON_STATE) {
if (Board_Board_State_event_consumed == 0 && 1) {
Board_Board_OnExit(BOARD_BOARD_FANOFFLEDON_STATE, _instance);
_instance->Board_Board_State = BOARD_BOARD_FANONLEDOFF_STATE;
Board_Board_OnEntry(BOARD_BOARD_FANONLEDOFF_STATE, _instance);
Board_Board_State_event_consumed = 1;
}
}
//End Region Board
//End dsregion Board
//Session list: 
}
void Board_handle_fromButton_release(struct Board_Instance *_instance) {
if(!(_instance->active)) return;
//Region Board
uint8_t Board_Board_State_event_consumed = 0;
if (_instance->Board_Board_State == BOARD_BOARD_FANONLEDOFF_STATE) {
if (Board_Board_State_event_consumed == 0 && 1) {
Board_Board_OnExit(BOARD_BOARD_FANONLEDOFF_STATE, _instance);
_instance->Board_Board_State = BOARD_BOARD_FANOFFLEDON_STATE;
Board_Board_OnEntry(BOARD_BOARD_FANOFFLEDON_STATE, _instance);
Board_Board_State_event_consumed = 1;
}
}
//End Region Board
//End dsregion Board
//Session list: 
}
int Board_handle_empty_event(struct Board_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region Board
if (_instance->Board_Board_State == BOARD_BOARD_WAITING_STATE) {
if (1) {
Board_Board_OnExit(BOARD_BOARD_WAITING_STATE, _instance);
_instance->Board_Board_State = BOARD_BOARD_FANONLEDOFF_STATE;
Board_Board_OnEntry(BOARD_BOARD_FANONLEDOFF_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:
void (*external_Board_send_toLED_LedON_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toLED_LedON_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toLED_LedON_listener = _listener;
}
void register_Board_send_toLED_LedON_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toLED_LedON_listener = _listener;
}
void Board_send_toLED_LedON(struct Board_Instance *_instance){
if (Board_send_toLED_LedON_listener != 0x0) Board_send_toLED_LedON_listener(_instance);
if (external_Board_send_toLED_LedON_listener != 0x0) external_Board_send_toLED_LedON_listener(_instance);
;
}
void (*external_Board_send_toLED_LedOFF_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toLED_LedOFF_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toLED_LedOFF_listener = _listener;
}
void register_Board_send_toLED_LedOFF_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toLED_LedOFF_listener = _listener;
}
void Board_send_toLED_LedOFF(struct Board_Instance *_instance){
if (Board_send_toLED_LedOFF_listener != 0x0) Board_send_toLED_LedOFF_listener(_instance);
if (external_Board_send_toLED_LedOFF_listener != 0x0) external_Board_send_toLED_LedOFF_listener(_instance);
;
}
void (*external_Board_send_toFAN_FanON_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toFAN_FanON_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toFAN_FanON_listener = _listener;
}
void register_Board_send_toFAN_FanON_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toFAN_FanON_listener = _listener;
}
void Board_send_toFAN_FanON(struct Board_Instance *_instance){
if (Board_send_toFAN_FanON_listener != 0x0) Board_send_toFAN_FanON_listener(_instance);
if (external_Board_send_toFAN_FanON_listener != 0x0) external_Board_send_toFAN_FanON_listener(_instance);
;
}
void (*external_Board_send_toFAN_FanOFF_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toFAN_FanOFF_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toFAN_FanOFF_listener = _listener;
}
void register_Board_send_toFAN_FanOFF_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toFAN_FanOFF_listener = _listener;
}
void Board_send_toFAN_FanOFF(struct Board_Instance *_instance){
if (Board_send_toFAN_FanOFF_listener != 0x0) Board_send_toFAN_FanOFF_listener(_instance);
if (external_Board_send_toFAN_FanOFF_listener != 0x0) external_Board_send_toFAN_FanOFF_listener(_instance);
;
}
void (*external_Board_send_port_Timer_timer_start_listener)(struct Board_Instance *, uint8_t, uint32_t)= 0x0;
void (*Board_send_port_Timer_timer_start_listener)(struct Board_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_Board_send_port_Timer_timer_start_listener(void (*_listener)(struct Board_Instance *, uint8_t, uint32_t)){
external_Board_send_port_Timer_timer_start_listener = _listener;
}
void register_Board_send_port_Timer_timer_start_listener(void (*_listener)(struct Board_Instance *, uint8_t, uint32_t)){
Board_send_port_Timer_timer_start_listener = _listener;
}
void Board_send_port_Timer_timer_start(struct Board_Instance *_instance, uint8_t id, uint32_t time){
if (Board_send_port_Timer_timer_start_listener != 0x0) Board_send_port_Timer_timer_start_listener(_instance, id, time);
if (external_Board_send_port_Timer_timer_start_listener != 0x0) external_Board_send_port_Timer_timer_start_listener(_instance, id, time);
;
}



/*****************************************************************************
 * Implementation for type : LED
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void LED_LED_SM_OnExit(int state, struct LED_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void LED_LED_SM_OnEntry(int state, struct LED_Instance *_instance) {
switch(state) {
case LED_LED_SM_STATE:{
_instance->LED_LED_SM_State = LED_LED_SM_READY_STATE;
LED_LED_SM_OnEntry(_instance->LED_LED_SM_State, _instance);
break;
}
case LED_LED_SM_READY_STATE:{
pinMode(_instance->LED_PIN11_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void LED_LED_SM_OnExit(int state, struct LED_Instance *_instance) {
switch(state) {
case LED_LED_SM_STATE:{
LED_LED_SM_OnExit(_instance->LED_LED_SM_State, _instance);
break;}
case LED_LED_SM_READY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void LED_handle_inLED_LedOFF(struct LED_Instance *_instance) {
if(!(_instance->active)) return;
//Region LED_SM
uint8_t LED_LED_SM_State_event_consumed = 0;
if (_instance->LED_LED_SM_State == LED_LED_SM_READY_STATE) {
if (LED_LED_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->LED_PIN11_var, LOW);
LED_LED_SM_State_event_consumed = 1;
}
}
//End Region LED_SM
//End dsregion LED_SM
//Session list: 
}
void LED_handle_inLED_LedON(struct LED_Instance *_instance) {
if(!(_instance->active)) return;
//Region LED_SM
uint8_t LED_LED_SM_State_event_consumed = 0;
if (_instance->LED_LED_SM_State == LED_LED_SM_READY_STATE) {
if (LED_LED_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->LED_PIN11_var,HIGH);
LED_LED_SM_State_event_consumed = 1;
}
}
//End Region LED_SM
//End dsregion LED_SM
//Session list: 
}

// Observers for outgoing messages:




#define MAX_INSTANCES 10
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
  return 0; // Dummy added by steffend
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

/*****************************************************************************
 * Implementation for type : FAN
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void FAN_FAN_OnExit(int state, struct FAN_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void FAN_FAN_OnEntry(int state, struct FAN_Instance *_instance) {
switch(state) {
case FAN_FAN_STATE:{
_instance->FAN_FAN_State = FAN_FAN_STANDBY_STATE;
FAN_FAN_OnEntry(_instance->FAN_FAN_State, _instance);
break;
}
case FAN_FAN_STANDBY_STATE:{
pinMode(_instance->FAN_PIN12_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void FAN_FAN_OnExit(int state, struct FAN_Instance *_instance) {
switch(state) {
case FAN_FAN_STATE:{
FAN_FAN_OnExit(_instance->FAN_FAN_State, _instance);
break;}
case FAN_FAN_STANDBY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void FAN_handle_inFAN_FanOFF(struct FAN_Instance *_instance) {
if(!(_instance->active)) return;
//Region FAN
uint8_t FAN_FAN_State_event_consumed = 0;
if (_instance->FAN_FAN_State == FAN_FAN_STANDBY_STATE) {
if (FAN_FAN_State_event_consumed == 0 && 1) {
digitalWrite(_instance->FAN_PIN12_var, LOW);
FAN_FAN_State_event_consumed = 1;
}
}
//End Region FAN
//End dsregion FAN
//Session list: 
}
void FAN_handle_inFAN_FanON(struct FAN_Instance *_instance) {
if(!(_instance->active)) return;
//Region FAN
uint8_t FAN_FAN_State_event_consumed = 0;
if (_instance->FAN_FAN_State == FAN_FAN_STANDBY_STATE) {
if (FAN_FAN_State_event_consumed == 0 && 1) {
digitalWrite(_instance->FAN_PIN12_var,HIGH);
FAN_FAN_State_event_consumed = 1;
}
}
//End Region FAN
//End dsregion FAN
//Session list: 
}

// Observers for outgoing messages:



#define timer2_NB_SOFT_TIMER 4
uint32_t timer2_timer[timer2_NB_SOFT_TIMER];
uint32_t  timer2_prev_1sec = 0;

uint8_t timer2_tic_flags = 0;

void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id);

uint8_t timer2_interrupt_counter = 0;
SIGNAL(TIMER2_OVF_vect) {
TCNT2 = 5;
timer2_interrupt_counter++;
if((timer2_interrupt_counter % 25) == 0) {
timer2_tic_flags |= 0b00000001;
}
if(timer2_interrupt_counter >= 25) {
timer2_interrupt_counter = 0;
}
}



//struct timer2_instance_type {
//    uint16_t listener_id;
//    /*INSTANCE_INFORMATION*/
//} timer2_instance;

struct timer2_instance_type timer2_instance;


void timer2_setup() {
	// Run timer2 interrupt up counting at 250kHz 
		 TCCR2A = 0;
		 TCCR2B = 1<<CS22 | 0<<CS21 | 0<<CS20;
		
		 //Timer2 Overflow Interrupt Enable
		 TIMSK2 |= 1<<TOIE2;


	timer2_prev_1sec = millis() + 1000;
}

void timer2_set_listener_id(uint16_t id) {
	timer2_instance.listener_id = id;
}

void timer2_timer_start(uint8_t id, uint32_t ms) {
if(id <timer2_NB_SOFT_TIMER) {
timer2_timer[id] = ms + millis();
}
}

void timer2_timeout(uint8_t id) {
uint8_t enqueue_buf[3];
enqueue_buf[0] = (1 >> 8) & 0xFF;
enqueue_buf[1] = 1 & 0xFF;
enqueue_buf[2] = id;
externalMessageEnqueue(enqueue_buf, 3, timer2_instance.listener_id);
}

void timer2_25ms_tic() {
{
uint8_t enqueue_buf[2];
enqueue_buf[0] = (2 >> 8) & 0xFF;
enqueue_buf[1] = 2 & 0xFF;
externalMessageEnqueue(enqueue_buf, 2, timer2_instance.listener_id);
}
}





void timer2_read() {
    uint32_t tms = millis();
    uint8_t t;
for(t = 0; t < 4; t++) {
if((timer2_timer[t] > 0) && (timer2_timer[t] < tms)) {
timer2_timer[t] = 0;
timer2_timeout(t);
}
}

    if (timer2_prev_1sec < tms) {
        timer2_prev_1sec += 1000;
    }
    if((timer2_tic_flags & 0b00000001) >> 0) {
timer2_25ms_tic();
timer2_tic_flags &= 0b11111110;
}

}
// Forwarding of messages timer2::Board::port_Timer::timer_start
void forward_timer2_Board_send_port_Timer_timer_start(struct Board_Instance *_instance, uint8_t id, uint32_t time){
timer2_timer_start(id, time);}

/*****************************************************************************
 * Implementation for type : BUTTON
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BUTTON_Button_OnExit(int state, struct BUTTON_Instance *_instance);
//Prototypes: Message Sending
void BUTTON_send_toBoard_press(struct BUTTON_Instance *_instance);
void BUTTON_send_toBoard_release(struct BUTTON_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void BUTTON_Button_OnEntry(int state, struct BUTTON_Instance *_instance) {
switch(state) {
case BUTTON_BUTTON_STATE:{
_instance->BUTTON_Button_State = BUTTON_BUTTON_RELEASED_STATE;
BUTTON_Button_OnEntry(_instance->BUTTON_Button_State, _instance);
break;
}
case BUTTON_BUTTON_RELEASED_STATE:{
break;
}
case BUTTON_BUTTON_PRESSED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void BUTTON_Button_OnExit(int state, struct BUTTON_Instance *_instance) {
switch(state) {
case BUTTON_BUTTON_STATE:{
BUTTON_Button_OnExit(_instance->BUTTON_Button_State, _instance);
break;}
case BUTTON_BUTTON_RELEASED_STATE:{
break;}
case BUTTON_BUTTON_PRESSED_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BUTTON_handle_clock_tic_ms25_tic(struct BUTTON_Instance *_instance) {
if(!(_instance->active)) return;
//Region Button
uint8_t BUTTON_Button_State_event_consumed = 0;
if (_instance->BUTTON_Button_State == BUTTON_BUTTON_RELEASED_STATE) {
if (BUTTON_Button_State_event_consumed == 0 && digitalRead(_instance->BUTTON_PIN_var)) {
BUTTON_Button_OnExit(BUTTON_BUTTON_RELEASED_STATE, _instance);
_instance->BUTTON_Button_State = BUTTON_BUTTON_PRESSED_STATE;
BUTTON_send_toBoard_press(_instance);
BUTTON_Button_OnEntry(BUTTON_BUTTON_PRESSED_STATE, _instance);
BUTTON_Button_State_event_consumed = 1;
}
}
else if (_instance->BUTTON_Button_State == BUTTON_BUTTON_PRESSED_STATE) {
if (BUTTON_Button_State_event_consumed == 0 &&  !(digitalRead(_instance->BUTTON_PIN_var))) {
BUTTON_Button_OnExit(BUTTON_BUTTON_PRESSED_STATE, _instance);
_instance->BUTTON_Button_State = BUTTON_BUTTON_RELEASED_STATE;
BUTTON_send_toBoard_release(_instance);
BUTTON_Button_OnEntry(BUTTON_BUTTON_RELEASED_STATE, _instance);
BUTTON_Button_State_event_consumed = 1;
}
}
//End Region Button
//End dsregion Button
//Session list: 
}

// Observers for outgoing messages:
void (*external_BUTTON_send_toBoard_press_listener)(struct BUTTON_Instance *)= 0x0;
void (*BUTTON_send_toBoard_press_listener)(struct BUTTON_Instance *)= 0x0;
void register_external_BUTTON_send_toBoard_press_listener(void (*_listener)(struct BUTTON_Instance *)){
external_BUTTON_send_toBoard_press_listener = _listener;
}
void register_BUTTON_send_toBoard_press_listener(void (*_listener)(struct BUTTON_Instance *)){
BUTTON_send_toBoard_press_listener = _listener;
}
void BUTTON_send_toBoard_press(struct BUTTON_Instance *_instance){
if (BUTTON_send_toBoard_press_listener != 0x0) BUTTON_send_toBoard_press_listener(_instance);
if (external_BUTTON_send_toBoard_press_listener != 0x0) external_BUTTON_send_toBoard_press_listener(_instance);
;
}
void (*external_BUTTON_send_toBoard_release_listener)(struct BUTTON_Instance *)= 0x0;
void (*BUTTON_send_toBoard_release_listener)(struct BUTTON_Instance *)= 0x0;
void register_external_BUTTON_send_toBoard_release_listener(void (*_listener)(struct BUTTON_Instance *)){
external_BUTTON_send_toBoard_release_listener = _listener;
}
void register_BUTTON_send_toBoard_release_listener(void (*_listener)(struct BUTTON_Instance *)){
BUTTON_send_toBoard_release_listener = _listener;
}
void BUTTON_send_toBoard_release(struct BUTTON_Instance *_instance){
if (BUTTON_send_toBoard_release_listener != 0x0) BUTTON_send_toBoard_release_listener(_instance);
if (external_BUTTON_send_toBoard_release_listener != 0x0) external_BUTTON_send_toBoard_release_listener(_instance);
;
}






/*****************************************************************************
 * Definitions for configuration : BoardApp
 *****************************************************************************/

//Declaration of instance variables
//Instance fabObj
// Variables for the properties of the instance
struct FAN_Instance fabObj_var;
// Variables for the sessions of the instance
//Instance redledObj
// Variables for the properties of the instance
struct LED_Instance redledObj_var;
// Variables for the sessions of the instance
//Instance arduinoObj
// Variables for the properties of the instance
struct Board_Instance arduinoObj_var;
// Variables for the sessions of the instance
//Instance buttonObj
// Variables for the properties of the instance
struct BUTTON_Instance buttonObj_var;
// Variables for the sessions of the instance


// Enqueue of messages Board::toLED::LedOFF
void enqueue_Board_send_toLED_LedOFF(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toLED >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toLED & 0xFF );
}
}
// Enqueue of messages Board::toLED::LedON
void enqueue_Board_send_toLED_LedON(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toLED >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toLED & 0xFF );
}
}
// Enqueue of messages Board::toFAN::FanOFF
void enqueue_Board_send_toFAN_FanOFF(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toFAN >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toFAN & 0xFF );
}
}
// Enqueue of messages Board::toFAN::FanON
void enqueue_Board_send_toFAN_FanON(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toFAN >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toFAN & 0xFF );
}
}
// Enqueue of messages BUTTON::toBoard::press
void enqueue_BUTTON_send_toBoard_press(struct BUTTON_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toBoard >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toBoard & 0xFF );
}
}
// Enqueue of messages BUTTON::toBoard::release
void enqueue_BUTTON_send_toBoard_release(struct BUTTON_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toBoard >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toBoard & 0xFF );
}
}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == timer2_instance.listener_id) {

}

}


//New dispatcher for messages
void dispatch_FanOFF(uint16_t sender) {
if (sender == arduinoObj_var.id_toFAN) {
FAN_handle_inFAN_FanOFF(&fabObj_var);

}

}


//New dispatcher for messages
void dispatch_LedOFF(uint16_t sender) {
if (sender == arduinoObj_var.id_toLED) {
LED_handle_inLED_LedOFF(&redledObj_var);

}

}


//New dispatcher for messages
void dispatch_ms25_tic(uint16_t sender) {
if (sender == timer2_instance.listener_id) {
BUTTON_handle_clock_tic_ms25_tic(&buttonObj_var);

}

}


//New dispatcher for messages
void dispatch_press(uint16_t sender) {
if (sender == buttonObj_var.id_toBoard) {
Board_handle_fromButton_press(&arduinoObj_var);

}

}


//New dispatcher for messages
void dispatch_LedON(uint16_t sender) {
if (sender == arduinoObj_var.id_toLED) {
LED_handle_inLED_LedON(&redledObj_var);

}

}


//New dispatcher for messages
void dispatch_FanON(uint16_t sender) {
if (sender == arduinoObj_var.id_toFAN) {
FAN_handle_inFAN_FanON(&fabObj_var);

}

}


//New dispatcher for messages
void dispatch_release(uint16_t sender) {
if (sender == buttonObj_var.id_toBoard) {
Board_handle_fromButton_release(&arduinoObj_var);

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 1:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_timeout = 2;
union u_timer_timeout_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_timeout_id;
u_timer_timeout_id.bytebuffer[0] = mbuf[mbufi_timer_timeout + 0];
mbufi_timer_timeout += 1;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_timeout_id.p /* id */ );
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_LedOFF = 2;
dispatch_LedOFF((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_FanOFF = 2;
dispatch_FanOFF((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_press = 2;
dispatch_press((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 2:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_ms25_tic = 2;
dispatch_ms25_tic((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_LedON = 2;
dispatch_LedON((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_FanON = 2;
dispatch_FanON((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_release = 2;
dispatch_release((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}

void forward_Board_send_port_Timer_timer_start(struct Board_Instance *_instance, uint8_t id, uint32_t time){
if(_instance->id_port_Timer == arduinoObj_var.id_port_Timer) {
forward_timer2_Board_send_port_Timer_timer_start(_instance, id, time);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 1:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
case 2:
if(msgSize == 2) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
}
}
}

void initialize_configuration_BoardApp() {
// Initialize connectors
register_external_Board_send_port_Timer_timer_start_listener(&forward_Board_send_port_Timer_timer_start);
register_Board_send_toLED_LedOFF_listener(&enqueue_Board_send_toLED_LedOFF);
register_Board_send_toLED_LedON_listener(&enqueue_Board_send_toLED_LedON);
register_Board_send_toFAN_FanOFF_listener(&enqueue_Board_send_toFAN_FanOFF);
register_Board_send_toFAN_FanON_listener(&enqueue_Board_send_toFAN_FanON);
register_BUTTON_send_toBoard_press_listener(&enqueue_BUTTON_send_toBoard_press);
register_BUTTON_send_toBoard_release_listener(&enqueue_BUTTON_send_toBoard_release);

// Init the ID, state variables and properties for external connector timer2
// Init the ID, state variables and properties for external connector timer2

// Network Initialization

timer2_instance.listener_id = add_instance(&timer2_instance);

timer2_setup();

// End Network Initialization

// Init the ID, state variables and properties for instance fabObj
fabObj_var.active = true;
fabObj_var.id_inFAN = add_instance( (void*) &fabObj_var);
fabObj_var.FAN_FAN_State = FAN_FAN_STANDBY_STATE;
fabObj_var.FAN_PIN12_var = 12;

FAN_FAN_OnEntry(FAN_FAN_STATE, &fabObj_var);
// Init the ID, state variables and properties for instance redledObj
redledObj_var.active = true;
redledObj_var.id_inLED = add_instance( (void*) &redledObj_var);
redledObj_var.LED_LED_SM_State = LED_LED_SM_READY_STATE;
redledObj_var.LED_PIN11_var = 11;

LED_LED_SM_OnEntry(LED_LED_SM_STATE, &redledObj_var);
// Init the ID, state variables and properties for instance buttonObj
buttonObj_var.active = true;
buttonObj_var.id_clock_tic = add_instance( (void*) &buttonObj_var);
buttonObj_var.id_toBoard = add_instance( (void*) &buttonObj_var);
buttonObj_var.BUTTON_Button_State = BUTTON_BUTTON_RELEASED_STATE;
buttonObj_var.BUTTON_PIN_var = 0;

BUTTON_Button_OnEntry(BUTTON_BUTTON_STATE, &buttonObj_var);
// Init the ID, state variables and properties for instance arduinoObj
arduinoObj_var.active = true;
arduinoObj_var.id_toLED = add_instance( (void*) &arduinoObj_var);
arduinoObj_var.id_toFAN = add_instance( (void*) &arduinoObj_var);
arduinoObj_var.id_fromButton = add_instance( (void*) &arduinoObj_var);
arduinoObj_var.id_port_Timer = add_instance( (void*) &arduinoObj_var);
arduinoObj_var.Board_Board_State = BOARD_BOARD_WAITING_STATE;

Board_Board_OnEntry(BOARD_BOARD_STATE, &arduinoObj_var);
}




void setup() {
initialize_configuration_BoardApp();

}

void loop() {

// Network Listener
timer2_read();
// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += Board_handle_empty_event(&arduinoObj_var);
}

    processMessageQueue();
}
