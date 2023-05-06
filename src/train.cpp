#include "train.h"

Train :: Train():first(nullptr), countOp(0) {}
void Train :: addCage(bool light) {
  Cage* items = new Cage;
  items->next = nullptr;
  items->prev = nullptr;
  Cage* temp;
  items->light = light;
  if (first == nullptr) {
    first = items;
  } else {
    if (first->next == nullptr) {
      first->next = items;
      first->prev = items;
      items->prev = first;
      items->next = first;
    } else {
      temp = first;
      while (temp->next != first) {
        temp = temp->next;
      }
      temp->next = items;
      items->prev = temp;
      items->next = first;
      first->prev  = items;
    }
  }
  countOp = 0;
}
int Train :: getLength() {
  Cage* temp;
  int sCage;
  countOp = 0;
  first->light = true;
  while (first->light == true) {
    temp = first->next;
    while (temp->light == false) {
      temp = temp->next;
      countOp++;
    }
    countOp++;
    temp->light = false;
    sCage = 1;
    while (temp->prev != first) {
      temp = temp->prev;
      countOp++;
      sCage++;
    }
    countOp++;
  }
  return sCage;
}
int Train :: getOpCount() {
  if (countOp == 0)
    getLength();
  return countOp;
}
