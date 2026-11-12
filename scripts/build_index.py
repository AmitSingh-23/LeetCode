#!/usr/bin/env python3
"""Rebuild the README index from the solution folders.

Each folder holds one solution plus a README with the problem's difficulty and
topic tags. This script reads those and writes the root README, so the counts
always reflect what is actually in the repository.

Usage:  python3 scripts/build_index.py
"""
import collections
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LANG = {".cpp": "C++", ".py": "Python", ".sql": "SQL", ".java": "Java", ".js": "JavaScript"}
# Topics shown as their own section, in this order. Tags not listed here are
# still counted in the summary table.
SECTIONS = [
    "Array", "String", "Hash Table", "Two Pointers", "Sliding Window", "Prefix Sum",
    "Binary Search", "Sorting", "Greedy", "Dynamic Programming", "Stack",
    "Heap (Priority Queue)", "Tree", "Depth-First Search", "Breadth-First Search",
    "Union-Find", "Graph Theory", "Backtracking", "Bit Manipulation", "Math",
    "Matrix", "Database",
]


def load():
    problems = []
    for name in os.listdir(ROOT):
        readme = os.path.join(ROOT, name, "README.md")
        if not os.path.isfile(readme) or not name[0].isdigit():
            continue
        text = open(readme, encoding="utf-8").read()
        title = re.search(r"^# (\d+)\. (.+)$", text, re.M)
        diff = re.search(r"\*\*(Easy|Medium|Hard)\*\*", text)
        topics = re.search(r"\*\*Topics:\*\* (.+)", text)
        files = [f for f in os.listdir(os.path.join(ROOT, name)) if f != "README.md"]
        if not title or not files:
            continue
        tags = [t.strip() for t in topics.group(1).split(",")] if topics else []
        tags = [t for t in tags if t and t != "N/A"]
        # Binary Tree problems belong under Tree as well.
        if "Binary Tree" in tags and "Tree" not in tags:
            tags.append("Tree")
        problems.append({
            "id": int(title.group(1)),
            "title": title.group(2).strip(),
            "dir": name,
            "difficulty": diff.group(1) if diff else "Unknown",
            "topics": tags,
            "langs": sorted({LANG.get(os.path.splitext(f)[1], os.path.splitext(f)[1]) for f in files}),
        })
    return sorted(problems, key=lambda p: p["id"])


def anchor(topic):
    return re.sub(r"[^a-z0-9 -]", "", topic.lower()).replace(" ", "-")


def build(problems):
    by_diff = collections.Counter(p["difficulty"] for p in problems)
    by_lang = collections.Counter(l for p in problems for l in p["langs"])
    by_topic = collections.Counter(t for p in problems for t in p["topics"])
    out = []
    out.append("# LeetCode Solutions\n")
    out.append("My accepted LeetCode solutions, mostly in C++. Each folder has the solution file and a README "
               "with the problem statement. New solutions are pushed automatically by the "
               "[LeetPush](https://github.com/LeetPushExtension/LeetPush) browser extension when a submission is accepted.\n")
    out.append("Profile: [leetcode.com/Amit_Singh_Bisht49](https://leetcode.com/Amit_Singh_Bisht49)\n")
    out.append("> This repository holds only the problems solved since the extension was set up, "
               "so the count here is lower than the total on my LeetCode profile.\n")
    out.append("## Summary\n")
    out.append("| Solutions | Easy | Medium | Hard | Languages |")
    out.append("| --- | --- | --- | --- | --- |")
    langs = ", ".join(f"{l} ({n})" for l, n in by_lang.most_common())
    out.append(f"| **{len(problems)}** | {by_diff.get('Easy', 0)} | {by_diff.get('Medium', 0)} | {by_diff.get('Hard', 0)} | {langs} |\n")
    out.append("## Topics\n")
    out.append("A problem can carry several topic tags, so it may appear under more than one topic. "
               "Tags come from LeetCode.\n")
    out.append("| Topic | Problems |")
    out.append("| --- | --- |")
    for t in SECTIONS:
        if by_topic.get(t):
            out.append(f"| [{t}](#{anchor(t)}) | {by_topic[t]} |")
    rest = sorted(((t, n) for t, n in by_topic.items() if t not in SECTIONS), key=lambda x: (-x[1], x[0]))
    if rest:
        out.append("| Other tags | " + ", ".join(f"{t} ({n})" for t, n in rest) + " |")
    out.append("")
    untagged = [p for p in problems if not p["topics"]]
    for t in SECTIONS:
        items = [p for p in problems if t in p["topics"]]
        if not items:
            continue
        out.append(f"## {t}\n")
        out.append("| # | Problem | Difficulty | Solution |")
        out.append("| --- | --- | --- | --- |")
        for p in items:
            out.append(f"| {p['id']} | {p['title']} | {p['difficulty']} | [{', '.join(p['langs'])}](./{p['dir']}) |")
        out.append("")
    if untagged:
        out.append("## Untagged\n")
        out.append("Problems whose README has no topic tags.\n")
        out.append("| # | Problem | Difficulty | Solution |")
        out.append("| --- | --- | --- | --- |")
        for p in untagged:
            out.append(f"| {p['id']} | {p['title']} | {p['difficulty']} | [{', '.join(p['langs'])}](./{p['dir']}) |")
        out.append("")
    out.append("---\n")
    out.append("This index is generated from the folders by [`scripts/build_index.py`](scripts/build_index.py). "
               "Run it after new solutions are pushed to refresh the counts.\n")
    return "\n".join(out)


if __name__ == "__main__":
    probs = load()
    with open(os.path.join(ROOT, "README.md"), "w", encoding="utf-8") as fh:
        fh.write(build(probs))
    print(f"Indexed {len(probs)} solutions")
