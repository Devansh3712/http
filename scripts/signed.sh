trailer=$(git log -1 --no-merges $commit --pretty='%B' | git interpret-trailers --parse 2>&1)
if [[ $trailer != Signed-off-by:* ]]; then
    printf '%s\n' "Commit is not signed, use git commit --amend --signoff" >&2
    exit 1
fi
