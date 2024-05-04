from um import count


def test_single():
    assert count("um") == 1
    assert count("um?") == 1


def test_single():
    assert count("Um, thanks for the album.") == 1


def test_multiple():
    assert count("Um, thanks, um...") == 2


def test_word():
    assert count("ummm, that's so yummy") == 0
