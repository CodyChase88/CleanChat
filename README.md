# PROJECT: CLEAN CHAT

Clean chat was inspired by seeing words replaced blandly with asterisks or special characters. "Clean Chat" instead replaces bad words with ones you may instead expect to hear on a playground (i.e. poo, shoot, dang, etc.).

## PERSONAL GOALS
- [x] Practice tokenizing an input string
- [x] Managing unknown input lengths and content
- [x] Using a control flow to check and replace keywords
- [ ] Become more exposed to/learn socket programming
- [ ] Creating a chat server
- [ ] Setting up the "Clean Chat" in the server's chat
- [ ] Connecting two clients

## PROGRAM METHODS
- Take a string input from a user
- Tokenize the string into individual words
- Place the words into an array of words
- Compare each word in that array to the words in the dirty words array
- If a word matches, swap it with the cooresponding variant from the clean words array
- Print out the new/clean string to the output

---
### NOTES
_21 Jan 2025_

Currently, the dirty/clean word arrays are limited due to their use being for testing. I would like to add additional variants of each word (dirty (fuck/fucking/fuckery) and clean (fudge/forking/freakery) for context checking. I also need to add in some better error checking and edge case handling.

---

### TODO
- [ ] Add error checking for allocation methods
- [ ] Expand dirty/clean word arrays
- [ ] Begin socket programming to setup server and server/client connections
- [ ] Allow clients to connect
- [ ] Allow clients to chat via text
- [ ] Run client chat entries through the Clean Chat filter
- [ ] Consider renaming _"Clean Chat"_ to _"Mackey Chat"_
##
