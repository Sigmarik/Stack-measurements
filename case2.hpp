for (size_t id = 0; id < 1e6l; id++) assert(CONCAT(TEST_SUBJECT, _push)(TEST_SUBJECT, rand()));
for (size_t id = 0; id < 1e6l; id++) CONCAT(TEST_SUBJECT, _pop)(TEST_SUBJECT);
for (size_t id = 0; id < 1e6l; id++) assert(CONCAT(TEST_SUBJECT, _push)(TEST_SUBJECT, rand()));

while (TEST_SUBJECT->size > 1e5l) {
    size_t stack_size = TEST_SUBJECT->size;
    for (size_t id = 0; id < stack_size / 2; id++) assert(CONCAT(TEST_SUBJECT, _pop)(TEST_SUBJECT));
    for (size_t id = 0; id < stack_size / 4; id++) assert(CONCAT(TEST_SUBJECT, _push)(TEST_SUBJECT, rand()));
}

for (size_t id = 0; id < 1e6l; id++) CONCAT(TEST_SUBJECT, _pop)(TEST_SUBJECT);
for (size_t id = 0; id < 1e6l; id++) assert(CONCAT(TEST_SUBJECT, _push)(TEST_SUBJECT, rand()));