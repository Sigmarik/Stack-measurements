for (size_t id = 0; id < 1e6l; id++) assert(CONCAT(TEST_SUBJECT, _push)(TEST_SUBJECT, rand()));
for (size_t id = 0; id < 1e6l; id++) CONCAT(TEST_SUBJECT, _pop)(TEST_SUBJECT);

for (size_t op_counter = 0; op_counter < 1e6l; op_counter++) {
    if (rand() & 1) assert(CONCAT(TEST_SUBJECT, _push)(TEST_SUBJECT, rand()));
    else CONCAT(TEST_SUBJECT, _pop)(TEST_SUBJECT);
}